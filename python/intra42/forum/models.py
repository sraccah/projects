#-*- coding: utf-8 -*-

from django.db import models

class Categorie(models.Model):  
    titre = models.CharField(max_length=100)
    date = models.DateTimeField(auto_now_add=True)
    def __unicode__(self):
        return self.titre

class Sous_categorie(models.Model):
    categorie = models.ForeignKey(Categorie)
    titre = models.CharField(max_length=100)
    date = models.DateTimeField(auto_now_add=True)
    def __unicode__(self):
        return self.titre

class Article(models.Model):
    categorie = models.ForeignKey(Categorie)
    sous_categorie = models.ForeignKey(Sous_categorie)
    titre = models.CharField(max_length=100)
    slug = models.SlugField(max_length=100)
    auteur = models.CharField(max_length=42)
    contenu = models.TextField(null=True)
    date = models.DateTimeField(auto_now_add=True, auto_now=False, verbose_name="Date de parution")
    def __unicode__(self):
        return self.titre

class Commentaire(models.Model):
    article = models.ForeignKey(Article)
    titre = models.CharField(max_length=100)
    auteur = models.CharField(max_length=42)
    contenu = models.TextField(null=True)
    date = models.DateTimeField(auto_now_add=True, auto_now=False, verbose_name="Date de parution")
    def __unicode__(self):
        return self.titre

class Contact(models.Model):
    titre = models.CharField(max_length=100)
    date = models.DateTimeField(auto_now_add=True, auto_now=False, verbose_name="Date de parution")

class Prio(models.Model):
    titre = models.CharField(max_length=100)
    date = models.DateTimeField(auto_now_add=True, auto_now=False, verbose_name="Date de parution")

class Ticket(models.Model):
    recepteur = models.ForeignKey(Contact)
    titre = models.CharField(max_length=100)
    auteur = models.CharField(max_length=42)
    contenu = models.TextField(null=True)
    priorite = models.ForeignKey(Prio)
    date = models.DateTimeField(auto_now_add=True, auto_now=False, verbose_name="Date de parution")
    def __unicode__(self):
        return self.titre
