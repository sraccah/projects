<?php
// src/Forum/ForumBundle/Form/ArticleEditType.php

namespace Forum\ForumBundle\Form;

use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\OptionsResolver\OptionsResolverInterface;
// Ajoutez ces deux use :
use Symfony\Component\Form\FormEvents;
use Symfony\Component\Form\FormEvent;


class ArticleEditType extends ArticleType // Ici, on hérite de ArticleType
{
  public function buildForm(FormBuilderInterface $builder, array $options)
  {
    $builder
      // … Ajoutez ici tous les champs stables, mais pas le champ publication
    ;

    $factory = $builder->getFormFactory();

    // On ajoute une fonction qui va écouter l'évènement PRE_SET_DATA
    $builder->addEventListener(
      FormEvents::PRE_SET_DATA, // Ici, on définit l'évènement qui nous intéresse
      function(FormEvent $event) use ($factory) { // Ici, on définit une fonction qui sera exécutée lors de l'évènement
        $article = $event->getData();
        // Cette condition est importante, on en reparle plus loin
        if (null === $article) {
          return; // On sort de la fonction lorsque $article vaut null
        }
        // Si l'article n'est pas encore publié, on ajoute le champ publication
        if (false === $article->getPublication()) {
          $event->getForm()->add(
            $factory->createNamed('publication', 'checkbox', null, array('required' => false))
          );
        } else { // Sinon, on le supprime
          $event->getForm()->remove('publication');
        }
      }
    );
  }

  // On modifie cette méthode car les deux formulaires doivent avoir un nom différent
  public function getName()
  {
    return 'Forum_Forumbundle_articleedittype';
  }
}