<?php
// src/Forum/ForumBundle/Form/CategorieType.php

namespace Forum\ForumBundle\Form;

use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\OptionsResolver\OptionsResolverInterface;

class CategorieType extends AbstractType
{
  public function buildForm(FormBuilderInterface $builder, array $options)
  {
    $builder
      ->add('nom', 'text')
    ;
  }

  public function setDefaultOptions(OptionsResolverInterface $resolver)
  {
    $resolver->setDefaults(array('data_class' => 'Forum\ForumBundle\Entity\Categorie'));
  }

  public function getName()
  {
    return 'forum_forumbundle_categorietype';
  }
}