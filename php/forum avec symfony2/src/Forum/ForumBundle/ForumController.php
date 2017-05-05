<?php

// src/Forum/ForumBundle/Controller/ForumController.php

namespace Forum\ForumBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

use Forum\ForumBundle\Entity\Categorie;
use Forum\ForumBundle\Entity\Commentaire;

use Forum\ForumBundle\Entity\ArticleCompetence;
use Forum\ForumBundle\Entity\Article;
use Forum\ForumBundle\Form\ArticleType;
use Forum\ForumBundle\Form\ArticleEditType;

use Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException;
use JMS\SecurityExtraBundle\Annotation\Secure;

class ForumController extends Controller
{
  public function indexAction($page)
  {
    $articles = $this->getDoctrine()
                     ->getManager()
                     ->getRepository('ForumForumBundle:Article')
                     ->getArticles(3, $page); // 3 articles par page : c'est totalement arbitraire !

    // On ajoute ici les variables page et nb_page à la vue
    return $this->render('ForumForumBundle:Forum:index.html.twig', array(
      'articles'   => $articles,
      'page'       => $page,
      'nombrePage' => ceil(count($articles)/3)
    ));
  }

  public function voirAction(Article $article)
  {
    // À ce stade, la variable $article contient une instance de la classe Article
    // Avec l'id correspondant à l'id contenu dans la route !

    // On récupère ensuite les articleCompetence pour l'article $article
    // On doit le faire à la main pour l'instant, car la relation est unidirectionnelle
    // C'est-à-dire que $article->getArticleCompetences() n'existe pas !
    $listeArticleCompetence = $this->getDoctrine()
                                   ->getManager()
                                   ->getRepository('ForumForumBundle:ArticleCompetence')
                                   ->findByArticle($article->getId());

    return $this->render('ForumForumBundle:Forum:voir.html.twig', array(
      'article'                 => $article,
      'listeArticleCompetence'  => $listeArticleCompetence
    ));
  }

  public function ajouterAction()
  {
    $article = new Article;
    $form = $this->createForm(new ArticleType, $article);

    $request = $this->get('request');
    if ($request->getMethod() == 'POST')
    {
        $form->bind($request);

        if ($form->isValid()) 
        {
            $em = $this->getDoctrine()->getManager();
            $em->persist($article);
            $em->flush();
        }
        return $this->redirect($this->generateUrl('forum_accueil'));
    }
    return $this->render('ForumForumBundle:Forum:ajouter.html.twig', array('form' => $form->createView()));
  }

  public function modifierAction(Article $article)
  {
    // On utiliser le ArticleEditType
    $form = $this->createForm(new ArticleEditType(), $article);

    $request = $this->getRequest();

    if ($request->getMethod() == 'POST') {
      $form->bind($request);

      if ($form->isValid()) {
        // On enregistre l'article
        $em = $this->getDoctrine()->getManager();
        $em->persist($article);
        $em->flush();

        // On définit un message flash
        $this->get('session')->getFlashBag()->add('info', 'Article bien modifié');

        return $this->redirect($this->generateUrl('forum_voir', array('id' => $article->getId())));
      }
    }

    return $this->render('ForumForumBundle:Forum:modifier.html.twig', array(
      'form'    => $form->createView(),
      'article' => $article
    ));

  }

  public function supprimerAction(Article $article)
  {
    // On crée un formulaire vide, qui ne contiendra que le champ CSRF
    // Cela permet de protéger la suppression d'article contre cette faille
    $form = $this->createFormBuilder()->getForm();

    $request = $this->getRequest();
    if ($request->getMethod() == 'POST') {
      $form->bind($request);

      if ($form->isValid()) {
        // On supprime l'article
        $em = $this->getDoctrine()->getManager();
        $em->remove($article);
        $em->flush();

        // On définit un message flash
        $this->get('session')->getFlashBag()->add('info', 'Article bien supprimé');

        // Puis on redirige vers l'accueil
        return $this->redirect($this->generateUrl('forum_accueil'));
      }
    }

    // Si la requête est en GET, on affiche une page de confirmation avant de supprimer
    return $this->render('ForumForumBundle:Forum:supprimer.html.twig', array(
      'article' => $article,
      'form'    => $form->createView()
    ));
  }

  public function menuAction($nombre)
  {
    $liste = $this->getDoctrine()
                  ->getManager()
                  ->getRepository('ForumForumBundle:Article')
                  ->findBy(
                    array(),          // Pas de critère
                    array('date' => 'desc'), // On trie par date décroissante
                    $nombre,         // On sélectionne $nombre articles
                    0                // À partir du premier
                  );

    return $this->render('ForumForumBundle:Forum:menu.html.twig', array(
      'liste_articles' => $liste // C'est ici tout l'intérêt : le contrôleur passe les variables nécessaires au template !
    ));
  }
}