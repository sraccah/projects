<?php
// src/Forum/ForumBundle/Entity/Image.php

namespace Forum\ForumBundle\Entity;

use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\HttpFoundation\File\UploadedFile;

/**
 * @ORM\Table()
 * @ORM\Entity(repositoryClass="Forum\ForumBundle\Entity\ImageRepository")
 */
class Image
{
  /**
   * @var integer $id
   *
   * @ORM\Column(name="id", type="integer")
   * @ORM\Id
   * @ORM\GeneratedValue(strategy="AUTO")
   */
  private $id;

  /**
   * @return integer 
   */
  public function getId()
  {
    return $this->id;
  }
}
