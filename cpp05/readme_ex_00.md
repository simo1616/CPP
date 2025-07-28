## Exercice 01 – “Rassemble-vous, larbins !”

### 1. Arborescence et livrables

Votre dossier `ex01/` doit contenir :

* **Makefile** (reprenant ou adaptant celui de l’ex00)
* **Bureaucrat.hpp / .cpp** (inchangés, sauf ajout de `signForm(Form&)`)
* **Utils.hpp** (exceptions et `operator<<` pour Bureaucrat)
* **Form.hpp / Form.h**
* **Form.cpp**
* **main.cpp** (nouveau, avec vos scénarios de test)

Aucun outil externe ou fonction interdite n’est utilisé.

---

### 2. Spécification de la classe **`Form`**

#### 2.1. Attributs (tous **privés**)

* `const std::string name;`
* `bool        isSigned;`  (initialisé à `false`)
* `const int   signGrade;`    (grade minimum pour signer)
* `const int   executeGrade;` (grade minimum pour exécuter)

#### 2.2. Constructeur

```cpp
Form(std::string const& name,
     int signGrade,
     int executeGrade);
```

* Initialise tous les membres :

  * `name` ← paramètre
  * `isSigned = false`
  * `signGrade` ← paramètre
  * `executeGrade` ← paramètre
* **Validation des grades** :

  * Si `signGrade < 1` **ou** `executeGrade < 1` → lancer `Form::GradeTooHighException`.
  * Si `signGrade > 150` **ou** `executeGrade > 150` → lancer `Form::GradeTooLowException`.

#### 2.3. Exceptions imbriquées

Dans `Form.hpp`, déclarez **à l’intérieur** de la classe :

```cpp
class GradeTooHighException : public std::exception {
  virtual const char* what() const throw();
};
class GradeTooLowException  : public std::exception {
  virtual const char* what() const throw();
};
```

Leur `what()` doit renvoyer un message clair (`"Form grade too high"` / `"Form grade too low"`).

#### 2.4. Accesseurs (`getters`)

Toutes `const` :

```cpp
std::string getName()         const;
bool        getIsSigned()     const;
int         getSignGrade()    const;
int         getExecuteGrade() const;
```

#### 2.5. Surcharge de l’opérateur `<<`

Déclarez le prototype en bas de `Form.hpp` :

```cpp
std::ostream& operator<<(std::ostream& os, Form const& f);
```

Son implémentation (dans `Form.cpp` ou un utils) affichera :

```
<form-name>, form signed: <true|false>, sign grade: <signGrade>, exec grade: <executeGrade>
```

#### 2.6. Méthode **`beSigned`**

```cpp
void beSigned(Bureaucrat const& b);
```

* Si `b.getGrade() <= signGrade` →

  ```cpp
  isSigned = true;
  ```
* Sinon →

  ```cpp
  throw GradeTooLowException();
  ```

---

### 3. Adaptation de la classe **`Bureaucrat`**

Ajoutez, dans `Bureaucrat.hpp` et implémentez dans `Bureaucrat.cpp` :

```cpp
void signForm(Form& f);
```

**Comportement** :

1. Tentez de signer :

   ```cpp
   f.beSigned(*this);
   ```
2. **Si** pas d’exception :

   ```cpp
   std::cout << getName()
             << " signed "
             << f.getName()
             << std::endl;
   ```
3. **Si** `GradeTooLowException` attrapée :

   ```cpp
   std::cout << getName()
             << " couldn’t sign "
             << f.getName()
             << " because "
             << e.what()
             << std::endl;
   ```

---

### 4. Scénarios de test (`main.cpp`)

1. **Construction de formulaires**

   * Valides :

     ```cpp
     Form f1("FormA", 50, 25);
     std::cout << f1;
     ```
   * Invalides (grades hors bornes) :

     ```cpp
     try { Form f2("Bad1", 0, 10); }
     catch (std::exception& e) { std::cerr << e.what(); }

     try { Form f3("Bad2", 10, 200); }
     catch (std::exception& e) { std::cerr << e.what(); }
     ```

2. **Signature directe**

   ```cpp
   Bureaucrat bob("Bob", 30);
   Form report("Report", 25, 5);
   // grade Bob (30) > 25 → trop bas
   bob.signForm(report);  // affiche « Bob couldn’t sign Report because ... »
   ```

3. **Signature réussie**

   ```cpp
   Bureaucrat alice("Alice", 5);
   Form contract("Contract", 10, 5);
   alice.signForm(contract); // « Alice signed Contract »
   std::cout << contract;    // isSigned == true
   ```

4. **Affichage complet** (`operator<<`)

   ```cpp
   std::cout << contract;
   ```

---

### 5. Validation finale

* **Pas** de warnings ou d’erreurs (`-Wall -Wextra -Werror -std=c++98`).
* **Vérifiez** qu’aucune fuite mémoire n’apparaît (Valgrind / AddressSanitizer).
* **Commentez** ou retirez tout `std::cout` de debug dans les constructeurs/destructeurs existants.

Voilà un plan détaillé pour une mise en œuvre claire et conforme !
