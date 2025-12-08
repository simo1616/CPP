

# Chapitre V – Exercice 00 : Conversion de types scalaires

### Répertoire de rendu

```
ex00/
```

### Fichiers à rendre

* `Makefile`
* `*.cpp`
* `*.h` ou `*.hpp`

### Fonctions autorisées

Toutes les fonctions permettant de convertir une chaîne en `int`, `float` ou `double`.
Elles t’aideront, mais elles ne feront pas tout le travail.

---

## Consigne

Écris une classe **`ScalarConverter`** qui contiendra **une seule méthode statique** :

```cpp
static void convert(std::string const& literal);
```

* Cette méthode prend en paramètre une chaîne représentant un littéral C++ sous sa forme la plus courante.
* Elle doit afficher la valeur de ce littéral convertie dans les **quatre types scalaires** suivants :

  * `char`
  * `int`
  * `float`
  * `double`

---

## Contraintes

* Comme la classe n’a pas besoin de stocker de données, elle **ne doit pas être instanciable**.
* À l’exception des `char`, seuls les littéraux en **notation décimale** seront utilisés.

---

## Détails par type

* **Littéraux `char`** :
  Exemples : `'c'`, `'a'`, …
  👉 Attention : les caractères non affichables ne doivent pas être utilisés en entrée.
  👉 Si une conversion vers `char` n’est pas affichable, affiche un message explicite.

* **Littéraux `int`** :
  Exemples : `0`, `-42`, `42`…

* **Littéraux `float`** :
  Exemples : `0.0f`, `-4.2f`, `4.2f`…
  👉 Tu dois aussi gérer les pseudo-littéraux : `-inff`, `+inff`, `nanf`.

* **Littéraux `double`** :
  Exemples : `0.0`, `-4.2`, `4.2`…
  👉 Tu dois aussi gérer les pseudo-littéraux : `-inf`, `+inf`, `nan`.

---

## Résultat attendu

* Tu dois d’abord **détecter le type** du littéral passé en paramètre.
* Ensuite, **le convertir depuis la chaîne vers son type réel**, puis enchaîner les **conversions explicites** vers les trois autres types.
* Enfin, **afficher les résultats** dans le format attendu.

⚠️ Si une conversion n’a pas de sens ou déborde (`overflow`), affiche un message clair :
`impossible`.

---

## Exemples d’exécution

```bash
$ ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

$ ./convert nan
char: impossible
int: impossible
float: nanf
double: nan

$ ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

---

👉 L’idée est donc de construire une **fonction de conversion centralisée**, capable de reconnaître l’entrée (`char`, `int`, `float`, `double`, ou pseudo-littéral spécial) et d’afficher toutes les conversions possibles de manière **lisible et cohérente**.
