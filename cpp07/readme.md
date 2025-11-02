Voici la **traduction complète et claire** de l’exercice que tu m’as envoyé — *C++ Module 07, Exercice 00 : Start with a few functions* :

---

### 🧩 Chapitre IV — Exercice 00 : Commencer avec quelques fonctions

**Nom du dossier :** `ex00/`
**Fichiers à rendre :** `Makefile`, `main.cpp`, `whatever.{h, hpp}`
**Fonctions interdites :** Aucune

---

### 🎯 Objectif

Implémente les **fonctions templates** suivantes :

* **swap**
  Échange les valeurs de deux paramètres donnés.
  → Ne retourne rien.

* **min**
  Compare les deux valeurs passées en paramètres et retourne **la plus petite**.
  → Si elles sont égales, retourne **la seconde**.

* **max**
  Compare les deux valeurs passées en paramètres et retourne **la plus grande**.
  → Si elles sont égales, retourne **la seconde**.

---

### ⚙️ Contraintes

Ces fonctions doivent pouvoir être appelées avec **n’importe quel type** d’argument.
La seule condition :

* Les deux arguments doivent être **du même type**,
* et ce type doit **supporter les opérateurs de comparaison** (`<`, `>`, etc.).

> 💡 Les templates doivent être **définis dans les fichiers d’en-tête**.

---

### 🧪 Exemple de code fourni

```cpp
int main(void) {
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}
```

---

### 🖥️ Sortie attendue

```
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

    ////////////////////////////////////////////////////////////////////////////////////    
   ///                                                                             ////     
  ///        ## 🧩 Chapitre V — Exercice 01 : Iter                                ////
 ///                                                                             ////
////////////////////////////////////////////////////////////////////////////////////



**Nom du dossier :** `ex01/`
**Fichiers à rendre :** `Makefile`, `main.cpp`, `iter.{h, hpp}`
**Fonctions interdites :** Aucune

---

### 🎯 Objectif

Implémente une **fonction template** `iter` qui prend **trois paramètres** et **ne retourne rien**.

* **Premier paramètre** :
  l’adresse d’un **tableau** (n’importe quel type).

* **Deuxième paramètre** :
  la **taille du tableau**, passée en **valeur constante** (`const`).

* **Troisième paramètre** :
  une **fonction** qui sera appelée sur **chaque élément du tableau**.

---

### ⚙️ Contraintes

* Ta fonction `iter` doit **fonctionner avec tout type de tableau**.
* Le **troisième paramètre** peut être une **fonction template instanciée**.
* La fonction passée en troisième paramètre peut prendre son argument :

  * soit par **référence constante (`const &`)**,
  * soit par **référence non constante (`&`)**,
    selon le contexte.

---

### ⚠️ Détail important

Tu dois réfléchir à **comment permettre le support** à la fois :

* des **éléments `const`**,
* et des **éléments non-const**
  dans ton implémentation de `iter`.

---

### 💡 Résumé

👉 Tu dois écrire une fonction template générique de la forme :

```cpp
template<typename T, typename F>
void iter(T *array, size_t length, F function);
```

Mais elle doit être capable de gérer à la fois :

* un tableau de `const T`,
* un tableau de `T` modifiable,
* et une fonction qui prend un `T&` ou un `const T&`.

---




    ////////////////////////////////////////////////////////////////////////////////////    
   ///      ////////////////////////////////////////////////////////////////////////////////////    
   ///      ////////////////////////////////////////////////////////////////////////////////////    
   ///  

## 🧩 Chapitre VI — Exercice 02 : Array

**Nom du dossier :** `ex02/`
**Fichiers à rendre :**
`Makefile`, `main.cpp`, `Array.{h, hpp}`
*(et éventuellement un fichier séparé `Array.tpp`)*

**Fonctions interdites :** Aucune

---

### 🎯 Objectif

Tu dois développer une **classe template** `Array` qui contient des éléments de type `T`
et qui implémente le comportement suivant :

---

### ⚙️ Comportement attendu

#### 1. **Constructeur sans paramètre**

Crée un **tableau vide**.

#### 2. **Constructeur avec un paramètre `unsigned int n`**

Crée un **tableau de `n` éléments**,
chaque élément étant **initialisé par défaut**.

> 💡 *Astuce du sujet :*
> Essaie de compiler ce code :
>
> ```cpp
> int *a = new int();
> std::cout << *a;
> ```
>
> Cela te montre comment les valeurs sont initialisées par défaut en C++.

---

#### 3. **Constructeur de copie et opérateur d’affectation**

Ces deux opérations doivent faire en sorte que :

* Modifier le tableau original **ne modifie pas la copie**,
* et inversement.
  → Il faut donc une **vraie copie en profondeur** (deep copy),
  et pas juste une copie d’adresse.

---

#### 4. **Allocation mémoire**

* Tu **dois utiliser** `operator new[]` pour allouer le tableau.
* Il est **interdit** de faire une allocation “préventive” (plus grande que nécessaire).
* Ton programme **ne doit jamais accéder à une zone mémoire non allouée**.

---

#### 5. **Accès aux éléments**

* Les éléments doivent être accessibles via **l’opérateur `[]`**.
* Si l’indice demandé est **hors limites**,
  ton opérateur `[]` doit **lancer une exception `std::exception`**.

---

#### 6. **Fonction membre `size()`**

* Retourne le **nombre d’éléments** contenus dans le tableau.
* Ne prend **aucun paramètre**.
* Ne doit **pas modifier** l’instance actuelle (donc doit être marquée `const`).

---

### 🧪 Ce qu’on attend de toi

Comme d’habitude :

* Ton code doit fonctionner correctement,
* et ton fichier `main.cpp` doit contenir des **tests complets** montrant que tout marche :

  * création,
  * copie,
  * affectation,
  * gestion des indices invalides,
  * et affichage de la taille.

---

### 📘 En résumé

Tu apprends ici :

* la **programmation générique** avec **templates de classes**,
* la **gestion manuelle de la mémoire dynamique** (`new[]`, `delete[]`),
* la **copie profonde** (constructeur de copie / opérateur `=`),
* et la **gestion des exceptions** avec `std::exception`.

---

Souhaites-tu que je t’explique ensuite **comment construire cette classe pas à pas**,
en te montrant **la logique interne de chaque méthode** (sans te donner le code complet) — pour t’aider à la comprendre avant de l’écrire toi-même ?

