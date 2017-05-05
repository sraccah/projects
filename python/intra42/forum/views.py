#-*- coding: utf-8 -*-

from datetime import datetime
from django.shortcuts import render, get_object_or_404, redirect
from django.contrib import auth
from django.contrib.auth.models import User
from django.core.context_processors import csrf
from django.views.generic import ListView
from django.views.generic.edit import DeleteView
from django.contrib.auth.decorators import login_required
from django.core.urlresolvers import reverse_lazy
from django.http import Http404, HttpResponse, HttpResponseRedirect
from forum.forms import ArticleForm, CommentaireForm, UserForm, TicketForm
from forum.models import Article, Categorie, Commentaire, Sous_categorie, Ticket

def login_view(request):
    username = request.POST.get('username', '')
    password = request.POST.get('password', '')
    user = auth.authenticate(username=username, password=password)
    if user is not None and user.is_active:
        # Correct password, and the user is marked "active"
        auth.login(request, user)
        # Redirect to a success page.
        return HttpResponseRedirect("/account/loggedin/")
    else:
        # Show an error page
        return HttpResponseRedirect("/account/invalid/")

def logout_view(request):
    auth.logout(request)
    # Redirect to a success page.
    return HttpResponseRedirect("/intra42/")


def create_view(request):
    if request.method == "POST":
        form = UserForm(request.POST)
        if form.is_valid():
            username = request.POST.get('username', '')
            password = request.POST.get('password', '')
            new_user = User.objects.create_user(**form.cleaned_data)
            new_user = auth.authenticate(username=username, password=password)
            if new_user is not None and new_user.is_active:
                # Correct password, and the user is marked "active"
                auth.login(request, new_user)
                # Redirect to a success page.
                return HttpResponseRedirect("/intra42/")
            else:
                # Show an error page
                return HttpResponseRedirect("/account/invalid/")
        else:
            form = UserForm() 
    else:
        form = UserForm() 
    return render(request, 'registration/register.html', {'form': form}) 

def home(request):
    return render(request, 'intra42/home.html', {'current_date': datetime.now()})

def profile(request):
    return render(request, 'intra42/profile.html', {'current_date': datetime.now()})

@login_required
def lire(request, id, slug):
    article = get_object_or_404(Article, id=id, slug=slug)
    if request.method == "POST":
        return redirect('/intra42/forum/commenter/')
    return render(request, 'intra42/lire.html', {'article':article})

@login_required
def ajouter(request):
    if request.method == "POST":
        form = ArticleForm(request.POST)
        if form.is_valid():
            article = form.save(commit=False)  # Ne sauvegarde pas directement l'article dans la base de données
            article.save()
            return redirect('/intra42/forum/')
    else:
        form = ArticleForm()
    return render(request, 'forum/ajouter.html', {'form':form})

@login_required
def commenter(request, id=1):
    if request.method == "POST":
        form = CommentaireForm(request.POST)
        article = get_object_or_404(Article, id=id)
        if form.is_valid():
            commentaire = form.save(commit=False)  # Ne sauvegarde pas directement le commentaire dans la base de données
            commentaire.article_id = article.id
            commentaire.save()
            return render(request, 'intra42/lire.html', {'article':article})
    else:
        form = CommentaireForm()
    return render(request, 'forum/commenter.html', {'form':form})

def ticket(request):
    if request.method == 'POST':  # S'il s'agit d'une requête POST
        form = TicketForm(request.POST)  # Nous reprenons les données
        if form.is_valid():
            ticket = form.save(commit=False)  # Ne sauvegarde pas directement le ticket dans la base de données
            ticket.save()
            return redirect('/intra42/ticket/')
    else:
        form = TicketForm()
    return render(request, 'intra42/ticket.html', locals())

def addition(request, nombre1, nombre2):    
    total = int(nombre1) + int(nombre2)
    # retourne nombre1, nombre2 et la somme des deux
    return render(request, 'intra42/addition.html', locals())

class Supprimer(DeleteView):
    model = Article
    success_url = reverse_lazy('forum_article') # This is where this view will
                                            # redirect the user
    template_name = 'forum/supprimer_article.html'

class ListeCategories(ListView):
    model = Categorie
    context_object_name = "categories"
    template_name = "forum/forum.html"
    paginate_by = 5

class ListeSous_categories(ListView):
    model = Sous_categorie
    context_object_name = "sous_categorie"
    template_name = "forum/forum.html"
    paginate_by = 5

class ListeArticles(ListView):
    model = Article
    context_object_name = "derniers_articles"
    template_name = "forum/forum.html"
    paginate_by = 5
    queryset = Article.objects.all().order_by('-date')
    def get_context_data(self, **kwargs):
       # Nous récupérons le contexte depuis la super-classe
       context = super(ListeArticles, self).get_context_data(**kwargs)
       # Nous ajoutons la liste des catégories, sans filtre particulier
       context['categories'] = Categorie.objects.all()
       context['sous_categorie'] = Sous_categorie.objects.all()
       return context
