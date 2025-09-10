// #include <iostream>
// #include <stdexcept>
// #include <cstdlib>


// class Exemp {
// 	private :

// 	public :
// 		Exemp() {x++;}
// 		static int x;
// 		int y;	
// };

// /* déclaration de la classe vect */
// class vect { 
// 		int nelem ;
// 		int * adr ;
// 	public :
// 		vect (int) ;
// 		~vect () ;
// 		int & operator [] (int) ;
// } ;
//  /* déclaration et définition d’une classe vect_limite (vide pour l’instant) */
// class vect_limite
// {  } ;
//  /* définition de la classe vect */
// vect::vect (int n)
// { 
// 	adr = new int [nelem = n] ;
// }
// vect::~vect ()
// { 
// 	delete adr ;
// }
// int & vect::operator [] (int i)
// { 
// 	if (i < 0 || i > nelem)
// 	{ 
// 		Exemp l ;
// 		throw (l) ;      // déclenche une exception de type vect_limite
// 	}
//   return adr [i] ;
// }



// int Exemp::x = 0;

// int main() {
//     Exemp a;
// 	a.y = 5;
	
//     std::cout << "a.x = \t" << a.x << std::endl;
//     std::cout << "a.y = \t" << a.y << std::endl;
// 	Exemp b;
// 	b.y = 9;
//     std::cout << "b.x = \t" << b.x << std::endl;
//     std::cout << "b.y = \t" << b.y << std::endl;
// 	Exemp d;
// 	d.y = 9;
// 	Exemp c(d);
// 	std::cout << "c.x = \t" << c.x << std::endl;
//     std::cout << "c.y = \t" << c.y << std::endl;

// 	vect_limite VL1;

// 	vect V1(3);
// 	vect V2(4);
// 	try {

// 		V1[-2];
// 		throw std::range_error ("anomalie 2");
// 	}
// 	catch (vect_limite l)  /* nom d’argument superflu ici */
// 	{ 
// 		std::cout << "exception limite \n" ;
// 	}
// 	catch (Exemp l)  /* nom d’argument superflu ici */
// 	{ 
// 		std::cout << "exception limite \n";
// 	}
// 	catch (std::range_error &re)  /* nom d’argument superflu ici */
// 	{ 
// 		std::cout << "exception limite \n" << re.what() << std::endl;
// 	}
// 	std::cout << "fin du programme a la fin \t"<< std::endl;


//     return 0;
// }


// #include <iostream>
// #include <new>    // pour std::set_new_handler, std::bad_alloc
// #include <cstdlib> // pour std::abort()

// // 1) Ton handler personnalisé :
// void monHandlerManqueMemoire()
// {
//     std::cerr << "!!! new a échoué : appel de monHandlerManqueMemoire()\n";
//     // Ici tu peux tenter de libérer des ressources, logger dans un fichier, etc.
// //  std::free(...);
// //  return; // si tu relâches de la mémoire, new va réessayer
//    // std::abort(); // sinon on termine le programme (pas de retry)
// 	throw std::bad_alloc();
// }

// int main()
// {
//     // 2) On installe le handler avant toute allocation
//     std::set_new_handler(monHandlerManqueMemoire);

//     try {
//         // 3) Allocation simple (sans nothrow) : 
//         int* ptr = new int;  
//         std::cout << "Allocation réussie pour ptr\n";
//         delete ptr;
//     }
//     catch (const std::bad_alloc& e) {
//         std::cerr << "Exception capturée : " << e.what() << "\n";
//         return 1;
//     }

//     // 4) Forcer un gros tableau pour déclencher le handler
//     size_t huge = static_cast<size_t>(-1) / sizeof(int);
//     try {
//         int* big = new int[huge];  
//         // si on arrive ici, l’OS a sur-commité la mémoire
//         delete[] big;
//     }
//     catch (const std::bad_alloc& e) {
//         std::cerr << "Après handler, std::bad_alloc levé : " 
//                   << e.what() << "\n";
//     }

//     return 0;
// }



#include <iostream>
#include <stdexcept>

using namespace std ;

class mon_exception_1 : public exception { 
	public :
		mon_exception_1 () {}
		const char * what() const throw() { 
			return "mon exception nummero 1" ; 
		}
} ;

class mon_exception_2 : public exception { 
	public :
		mon_exception_2 () {}
		const char * what() const throw() { 
			return "mon exception nummero 2" ; 
		}
} ;

int main()
{ 
	try { 
		cout << "bloc try 1\n" ;
		throw mon_exception_1() ;   
	}
		catch (exception & e) 
	{ 
		cout << "exception : " << e.what() << "\n" ;
	}
	try
	{ 
		cout << "bloc try 2\n" ;
		throw mon_exception_2() ;   
	}
		catch (exception & e) 
	{ 
		cout << "exception : " << e.what() << "\n" ;
	}
}