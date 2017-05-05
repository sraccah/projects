<?php
// src/Forum/ForumBundle/Entity/ArticleCompetence.php

namespace Forum\ForumBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 */
class ArticleCompetence
{
  /**
   * @ORM\Id
   * @ORM\ManyToOne(targetEntity="Forum\ForumBundle\Entity\Article")
   */
  private $article;

  /**
   * @ORM\Id
   * @ORM\ManyToOne(targetEntity="Forum\ForumBundle\Entity\Competence")
   */
  private $competence;

  /**
   * @ORM\Column()
   */
  private $niveau; // Ici j'ai un attribut de relation, que j'ai appelé « niveau »

  /**
   * @param string $niveau
   * @return Article_Competence
   */
  public function setNiveau($niveau)
  {
    $this->niveau = $niveau;
    return $this;
  }

  /**
   * @return string
   */
  public function getNiveau()
  {
    return $this->niveau;
  }

  /**
   * @param Forum\ForumBundle\Entity\Article $article
   * @return ArticleCompetence
   */
  public function setArticle(\Forum\ForumBundle\Entity\Article $article)
  {
    $this->article = $article;
    return $this;
  }

  /**
   * @return Forum\ForumBundle\Entity\Article
   */
  public function getArticle()
  {
    return $this->article;
  }

  /**
   * @param Forum\ForumBundle\Entity\Competence $competence
   * @return ArticleCompetence
   */
  public function setCompetence(\Forum\ForumBundle\Entity\Competence $competence)
  {
    $this->competence = $competence;
    return $this;
  }

  /**
   * @return Forum\ForumBundle\Entity\Competence
   */
  public function getCompetence()
  {
    return $this->competence;
  }
}
