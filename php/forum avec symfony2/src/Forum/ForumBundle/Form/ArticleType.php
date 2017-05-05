<?php

namespace Forum\ForumBundle\Form;

use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\OptionsResolver\OptionsResolverInterface;

class ArticleType extends AbstractType
{
    /**
     * @param FormBuilderInterface $builder
     * @param array $options
     */
    public function buildForm(FormBuilderInterface $builder, array $options)
    {
        $builder
            ->add('date',        'date')
            ->add('titre',       'text')
            ->add('contenu',     'textarea')
            ->add('auteur',      'text')
            ->add('publication', 'checkbox', array('required' => false))
            ;
    }
    
    /**
     * @param OptionsResolverInterface $resolver
     */
    public function setDefaultOptions(OptionsResolverInterface $resolver)
    {
        $resolver->setDefaults(array('data_class' => 'Forum\ForumBundle\Entity\Article'));
    }

    /**
     * @return string
     */
    public function getName()
    {
        return 'forum_forumbundle_article';
    }
}
