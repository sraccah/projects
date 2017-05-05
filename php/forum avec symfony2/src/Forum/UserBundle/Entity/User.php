<?php
// src/Forum/UserBundle/Entity/User.php

namespace Forum\UserBundle\Entity;
use Symfony\Component\Security\Core\User\UserInterface;

use FOS\UserBundle\Entity\User as BaseUser;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity(repositoryClass="Forum\UserBundle\Entity\UserRepository")
 * @ORM\Entity
 * @ORM\Table(name="forum_user")
 */
class User extends BaseUser
{
  /**
   * @ORM\Id
   * @ORM\Column(type="integer")
   * @ORM\GeneratedValue(strategy="AUTO")
   */
  protected $id;

    /**
     * Get id
     *
     * @return integer 
     */
    public function getId()
    {
        return $this->id;
    }
}
