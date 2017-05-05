<?php
// src/Forum/ForumBundle/DataFixtures/ORM/Competences.php

namespace Forum\ForumBundle\DataFixtures\ORM;

use Doctrine\Common\DataFixtures\FixtureInterface;
use Doctrine\Common\Persistence\ObjectManager;
use Forum\ForumBundle\Entity\Competence;

class Competences implements FixtureInterface
{
  public function load(ObjectManager $manager)
  {
    // Liste des noms de compétences à ajouter
    $noms = array('Doctrine', 'Formulaire', 'Twig');

    foreach($noms as $i => $nom)
    {
      // On crée la compétence
      $liste_competences[$i] = new Competence();
      $liste_competences[$i]->setNom($nom);

      // On la persiste
      $manager->persist($liste_competences[$i]);
    }                            

    // On déclenche l'enregistrement
    $manager->flush();
  }
}