#-*- coding: utf-8 -*-

from django import forms
from models import Article, Commentaire, Ticket
from django.contrib.auth.models import User

class UserForm(forms.ModelForm):
    class Meta:
        model = User
        fields = ('username', 'last_name', 'first_name', 'email', 'password',)
        widgets = {
            'password': forms.PasswordInput(),
        }

class ArticleForm(forms.ModelForm):
    class Meta:
        model = Article
        fields = ('titre', 'slug', 'auteur', 'contenu', 'categorie', 'sous_categorie',)

class CommentaireForm(forms.ModelForm):
    class Meta:
        model = Commentaire
        fields = ('titre', 'auteur', 'contenu',)

class TicketForm(forms.ModelForm):
    class Meta:
        model = Ticket
        fields = ('recepteur', 'titre', 'auteur', 'contenu', 'priorite',)
