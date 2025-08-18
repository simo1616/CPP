```markdown
# Chapitre V - Exercice 02 : « Non, il vous faut le formulaire 28B, pas le 28C… »

## Exercice 02 : Non, il vous faut le formulaire 28B, pas le 28C…

### Répertoire de rendu

```

ex02/

````

### Fichiers à rendre

- `Makefile`
- `main.cpp`
- **Bureaucrat** :
  - `Bureaucrat.hpp`
  - `Bureaucrat.cpp`
- **Formulaire abstrait** :
  - `AForm.hpp`
  - `AForm.cpp`
- **Formulaires concrets** :
  - `ShrubberyCreationForm.hpp`
  - `ShrubberyCreationForm.cpp`
  - `RobotomyRequestForm.hpp`
  - `RobotomyRequestForm.cpp`
  - `PresidentialPardonForm.hpp`
  - `PresidentialPardonForm.cpp`

> **Interdiction** : Aucune fonction n’est interdite pour cet exercice.

---

## Contexte

Vous avez maintenant des formulaires de base, place à ceux qui font vraiment quelque chose !  
Rappelez-vous que la classe de base `Form` doit devenir une **classe abstraite** et être renommée **`AForm`**.
Les attributs (nom, état, grades) restent privés et gérés dans cette classe de base.

---

## Spécifications de la classe abstraite `AForm`

1. **Attributs privés** (dans `AForm`) :
   - `name` : nom _constant_ du formulaire.
   - `isSigned` : booléen indiquant si le formulaire est signé.
   - `gradeToSign` : grade _constant_ requis pour signer.
   - `gradeToExecute` : grade _constant_ requis pour exécuter.

2. **Constructeur**
   - Initialise le nom, les grades requis et l’état (non signé).
   - Si un grade est hors de l’intervalle [1,150], lever `AForm::GradeTooHighException` ou `AForm::GradeTooLowException`.

3. **Méthode virtuelle pure**
   - `virtual void executeAction() const = 0;`  
     Cette méthode effectuera l’action spécifique dans les classes dérivées.

4. **Méthode `execute(Bureaucrat const & executor) const`**
   - Vérifie que le formulaire est signé (`isSigned == true`).
   - Vérifie que `executor.getGrade() <= gradeToExecute` (plus le grade est petit, plus le pouvoir est grand).
   - Si tout est OK, appelle `executeAction()`.
   - Sinon, lance l’exception appropriée (`FormNotSignedException` ou `GradeTooLowException`).

5. **Accesseurs** et **surcharge de `<<`**
   - Getters pour nom, état, grades.
   - Surcharge de l’opérateur `<<` pour afficher toutes les infos du formulaire.

---

## Formulaires concrets

### 1. `ShrubberyCreationForm`
- **Grades requis** : signer = 145, exécuter = 137
- **Action** : crée un fichier `<target>_shrubbery` et y écrit un arbre ASCII.
- **Constructeur** : prend un paramètre `std::string const & target`.

### 2. `RobotomyRequestForm`
- **Grades requis** : signer = 72, exécuter = 45
- **Action** : affiche des bruits de forage, puis indique que
  `<target>` a été robotomisé avec succès 50% du temps,
  sinon que la robotisation a échoué.

### 3. `PresidentialPardonForm`
- **Grades requis** : signer = 25, exécuter = 5
- **Action** : affiche que `<target>` a été gracié par Zaphod Beeblebrox.

> **Constructeurs** : chacun ne prend qu’un seul paramètre `target`.

---

## Intégration avec `Bureaucrat`

Dans la classe **`AForm`**, implémentez la méthode :
```cpp
void execute(Bureaucrat const & executor) const;
````

et, dans **chaque classe concrète**, définissez `executeAction()` pour réaliser l’action.

Ajoutez ensuite à **`Bureaucrat`** la méthode :

```cpp
void executeForm(AForm const & form) const;
```

* Tente d’exécuter le formulaire (`form.execute(*this)`).
* Si ça réussit, affiche :

  ```
  <bureaucrat> executed <form>
  ```
* Sinon, capture l’exception et affiche un message explicite d’erreur.

---

## Tests

Créez un `main.cpp` qui vérifie :

* Création de chaque formulaire (valides/invalides).
* Signature par un bureaucrate de grade suffisant ou insuffisant.
* Exécution (ou tentative) pour chaque type de formulaire et chaque grade de bureaucrate.

---

Bonne programmation et que la bureaucratie soit avec vous !

```
```
