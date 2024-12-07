# **Jeu de la vie**

## Contexte :

Le jeu de la vie est un automate cellulaire proposé par le mathématicien John Conway. Il permet de suivre l’évolution d’une population de cellules au cours du temps. Ces cellules sont dans une grille en deux dimensions et chaque cellule peut avoir deux états, soit vivante, soit morte.  
Le temps va être appelé itération et chaque cellule change d’état selon ce temps.

Pour cela deux règles définissent le jeu de la vie :

- Une cellule morte possédant exactement trois voisines devient vivante.

- Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.

## Sommaire :

## Documentation Utilisateur :

### Comment implémenter le programme ?

Pour impléter le programme, il faut le télécharger ou le cloner.

#### Télécharger le programme :

<img src="image.png" width="300" />

Maintenant, il faut déziper le dossier et ajouter manuellement les fichiers dans le dossier que vous souhaité.

Vous avez maintenant accès au programme.

#### Cloner le programme sur VSCODE:

1 - Connectez vous à GITHUB sur VSCODE.

2 - Copié collé ce lien :

<img src="image-1.png" width="300" />

3 - Faite CTRL SHIFT P sur VSCODE et séléctioner "GIT : CLONE".

<img src="image-2.png" width="300" />

4 - Séléctionner "Clone From GITHUB".

<img src="image-3.png" width="300" />

5 - Coller le lien :

<img src="image-4.png" width="300" />

6 - Puis choissisez le répertoire où vous souhaité cloner le programme.

### Comment executer le programme ?

Pour executer le programme, il faut suivre de nombres étapes.

#### Ajoutez / Modifier un fichier d'entrée :

- Dans le dossier, il existe par défaut un fichier "test.txt" comprenant une matrice en 50x50.

<img src="image-5.png" width="300" />

- Vous pouvez modifier cette matrice comme vous voulez, la première ligne correspond aux dimensions et la deuxième,troisième... C'est le contenu de la matrice.

- Pensez à faire correspondre les dimensions aux nombres d'entiers que vous avez ajouter et à rentrer seulement des 1 ou 0 sinon la matrice n'est pas valide.

- Vous pouvez créer votre propre fichier texte.

#### Installer la bibliothèque SFML :

- Cette bibliothèque est obligatoire pour le fonctionnement de l'interface graphique.

Pour Ubuntu :

Ecrivez dans le terminal : `sudo apt update`
Puis : `sudo apt install libsfml-dev`

#### Creer les fichiers exécutable et l'éxécuter :

Dans les fichiers, il y a un makefile qui fonctionne seulement avec g++ qui permet de convertir les fichiers en executables.

Pour créer des fichiers executables , rentrer dans votre termine ces commandes :

- `make clean` => Pour effacer les anciens fichiers exécutables.
- `make` => Pour creer les nouveaux fichiers exécutables.

Pour exécuter le programme, il faut rentrer dans le terminal :

- `./simulation` => Permet d'exécuter les fichiers.

### Comment fonctionne le programme ?

1 - Entrez le nom de votre fichier d'entrée avec l'extension, si vous avez garder celui par défaut alors entrez `test.txt"`

2 - Maintenant, Choissisez l'interface que vous souhaitez en écrivant 1 pour l'interface console et 2 pour l'interface graphique.

Si vous avez choisi, l'interface console alors :

- Entrez le nombre maximum d'itération que vous souhaitez.
- Normalment le jeu s'affiche dans la console et sauvegarde chaque itérations dans un dossier de sortie `nomfichierentree_out`

<img src="image-6.png" width="300" />

Si vous avez choisi, l'interface graphique alors :

- Entrez le nombre maximum d'itération que vous souhaitez.
- Entre le temps entre chaque itération.
- Normalement le jeu d'affiche dans une interface graphique.

<img src="image-7.png" width="300" />

## Documentation Technique :
