#-*- coding: utf-8 -*-

from django.conf.urls import patterns, include, url
from django.contrib import admin
from django.contrib.auth.views import login, logout

admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'intra42.views.home', name='home'),
    # existing patterns here...
    url(r'^accounts/login/$',  login),
    url(r'^accounts/logout/$', logout),
    url(r'^intra42/', include('forum.urls')),
    url(r'^admin/', include(admin.site.urls)),
)
