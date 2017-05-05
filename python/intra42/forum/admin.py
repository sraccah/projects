# -*- coding:utf-8 -*-

from django.contrib import admin
from forum.models import Categorie, Article, Commentaire, Sous_categorie, Ticket, Contact, Prio

class ArticleAdmin(admin.ModelAdmin):

    # Configuration de la liste d'articles
    list_display   = ('titre', 'categorie', 'sous_categorie', 'auteur', 'date')
    list_filter    = ('auteur','categorie', 'sous_categorie', )
    date_hierarchy = 'date'
    ordering       = ('date', )
    search_fields  = ('titre', 'contenu')
    prepopulated_fields = {'slug': ('titre', ), }

    # Configuration du formulaire d'édition
    fieldsets = (
    	# Fieldset 1 : meta-info (titre, auteur…)
       ('Général', {
            'classes': ['collapse',],
            'fields': ('titre', 'slug', 'auteur', 'categorie', 'sous_categorie')
        }),
        # Fieldset 2 : contenu de l'article
        ('Contenu de l\'article', {
           'description': u'Le formulaire accepte les balises HTML. Utilisez-les à bon escient !',
           'fields': ('contenu', )
        }),
    )

    # Colonnes personnalisées 
    def apercu_contenu(self, article):
        """ 
        Retourne les 40 premiers caractères du contenu de l'article. S'il
        y a plus de 40 caractères, il faut rajouter des points de suspension.
        """
        text = article.contenu[0:40]
        if len(article.contenu) > 40:
            return '%s...' % text
        else:
            return text

    # En-tête de notre colonne
    apercu_contenu.short_description = u'Aperçu du contenu'

class CategorieAdmin(admin.ModelAdmin):

    # Configuration de la liste de categories
    list_display   = ('titre', 'date')
    date_hierarchy = 'date'
    ordering       = ('date', )

    # Configuration du formulaire d'édition
    fieldsets = (
        # Fieldset 1 : meta-info (titre, auteur…)
       ('Général', {
            'fields': ('titre',)
        }),
    )

    # Colonnes personnalisées 
    def apercu_contenu(self, article):
        """ 
        Retourne les 40 premiers caractères du nom de la categorie. S'il
        y a plus de 40 caractères, il faut rajouter des points de suspension.
        """
        text = categorie.titre[0:40]
        if len(categorie.titre) > 40:
            return '%s...' % text
        else:
            return text

    # En-tête de notre colonne
    apercu_contenu.short_description = u'Aperçu du contenu'

class Sous_categorieAdmin(admin.ModelAdmin):

    # Configuration de la liste de categories
    list_display   = ('titre', 'categorie', 'date')
    date_hierarchy = 'date'
    ordering       = ('date', )

    # Configuration du formulaire d'édition
    fieldsets = (
        # Fieldset 1 : meta-info (titre, auteur…)
       ('Général', {
            'fields': ('titre', 'categorie', )
        }),
    )

    # Colonnes personnalisées 
    def apercu_contenu(self, categorie):
        """ 
        Retourne les 40 premiers caractères du nom de la sous-categorie. S'il
        y a plus de 40 caractères, il faut rajouter des points de suspension.
        """
        text = scategorie.titre[0:40]
        if len(scategorie.titre) > 40:
            return '%s...' % text
        else:
            return text

    # En-tête de notre colonne
    apercu_contenu.short_description = u'Aperçu du contenu'

class CommentaireAdmin(admin.ModelAdmin):

    # Configuration de la liste d'articles
    list_display   = ('titre', 'auteur', 'contenu', 'date')
    list_filter    = ('auteur',)
    date_hierarchy = 'date'
    ordering       = ('date', )
    search_fields  = ('titre', 'contenu')

    # Configuration du formulaire d'édition
    fieldsets = (
        # Fieldset 1 : meta-info (titre, auteur…)
       ('Général', {
            'classes': ['collapse',],
            'fields': ('titre', 'auteur',)
        }),
        # Fieldset 2 : contenu du commentaire
        ('Contenu de l\'article', {
           'description': u'Le formulaire accepte les balises HTML. Utilisez-les à bon escient !',
           'fields': ('contenu', )
        }),
    )

    # Colonnes personnalisées 
    def apercu_contenu(self, article):
        """ 
        Retourne les 40 premiers caractères du contenu de l'article. S'il
        y a plus de 40 caractères, il faut rajouter des points de suspension.
        """
        text = commentaire.contenu[0:40]
        if len(commentaire.contenu) > 40:
            return '%s...' % text
        else:
            return text

    # En-tête de notre colonne
    apercu_contenu.short_description = u'Aperçu du contenu'

class TicketAdmin(admin.ModelAdmin):

    # Configuration de la liste de tickets
    list_display   = ('recepteur', 'titre', 'auteur', 'contenu', 'priorite', 'date')
    list_filter    = ('recepteur', 'auteur', 'priorite')
    date_hierarchy = 'date'
    ordering       = ('date', )
    search_fields  = ('recepteur', 'titre', 'contenu', 'priorite')

    # Configuration du formulaire d'édition
    fieldsets = (
        # Fieldset 1 : meta-info (titre, auteur…)
       ('Général', {
            'classes': ['collapse',],
            'fields': ('recepteur', 'auteur', 'priorite')
        }),
        # Fieldset 2 : contenu du ticket
        ('Contenu du ticket', {
           'description': u'Le formulaire accepte les balises HTML. Utilisez-les à bon escient !',
           'fields': ('titre', 'contenu', )
        }),
    )

    # Colonnes personnalisées 
    def apercu_contenu(self, article):
        """ 
        Retourne les 40 premiers caractères du contenu du ticket. S'il
        y a plus de 40 caractères, il faut rajouter des points de suspension.
        """
        text = ticket.contenu[0:40]
        if len(ticket.contenu) > 40:
            return '%s...' % text
        else:
            return text

    # En-tête de notre colonne
    apercu_contenu.short_description = u'Aperçu du contenu'

class ContactAdmin(admin.ModelAdmin):

    # Configuration de la liste de categories
    list_display   = ('titre', 'date')
    date_hierarchy = 'date'
    ordering       = ('date', )

    # Configuration du formulaire d'édition
    fieldsets = (
        # Fieldset 1 : meta-info (titre, auteur…)
       ('Général', {
            'fields': ('titre',)
        }),
    )

class PrioAdmin(admin.ModelAdmin):

    # Configuration de la liste de categories
    list_display   = ('titre', 'date')
    date_hierarchy = 'date'
    ordering       = ('date', )

    # Configuration du formulaire d'édition
    fieldsets = (
        # Fieldset 1 : meta-info (titre, auteur…)
       ('Général', {
            'fields': ('titre',)
        }),
    )

admin.site.register(Categorie, CategorieAdmin)
admin.site.register(Article, ArticleAdmin)
admin.site.register(Commentaire, CommentaireAdmin)
admin.site.register(Sous_categorie, Sous_categorieAdmin)
admin.site.register(Ticket, TicketAdmin)
admin.site.register(Contact, ContactAdmin)
admin.site.register(Prio, PrioAdmin)