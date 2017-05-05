#-*- coding: utf-8 -*-

from django.conf.urls import patterns, url, include
from django.contrib.auth.decorators import login_required
from forum.views import ListeArticles, Supprimer
from forum.models import Article

urlpatterns = patterns('forum.views',
    url(r'^$', 'home'),
    url(r'^login/$',  'login_view'),
    url(r'^logout/$', 'logout_view'),
    url(r'^register/$', 'create_view'),
    url(r'^profile/$',  'profile'),
    url(r'^forum/$', login_required(ListeArticles.as_view()), name="forum_article"),
    # Nous allons réécrire l'URL de la page article (id + slug)
    url(r'^forum/(?P<id>\d+)-(?P<slug>.+)/$', 'lire'), # Vue d'un article
    url(r'^supprimer/(?P<pk>\d+)/$', login_required(Supprimer.as_view()), name="supprimer"),
    url(r'^forum/ajouter/$', 'ajouter'), # Ajouter un article
    url(r'^forum/commenter/$', 'commenter'), # Commenter un article
    url(r'^ticket/$', 'ticket'),
    url(r'^addition/(?P<nombre1>\d+)/(?P<nombre2>\d+)/$', 'addition'),
)
