#include <iostream>
#include <vector>
#include "clases.h"

using namespace std;

// ################################################################# CLASE PADRE #################################################################

// Constructor del ejercicio
Ejercicio::Ejercicio(
	int codigo_identificador,
	string nombre,
	string tipo_ejercicio,
	string nivel_intensidad,
	int tiempo_estimado,
	string descripcion,
	int ultima_semana
) {
	this->codigo_identificador = codigo_identificador;
	this->nombre = nombre;
	this->tipo_ejercicio = tipo_ejercicio;
	this->nivel_intensidad = nivel_intensidad;
	this->tiempo_estimado = tiempo_estimado;
	this->descripcion = descripcion;
	this->ultima_semana = ultima_semana;
}

// Destructor del ejercicio
Ejercicio::~Ejercicio() {
}

// Metodos getters
int Ejercicio::get_codigo_identificador() {
	return this->codigo_identificador;
}

string Ejercicio::get_nombre() {
	return this->nombre;
}

string Ejercicio::get_tipo_ejercicio() {
	return this->tipo_ejercicio;
}

string Ejercicio::get_nivel_intensidad() {
	return this->nivel_intensidad;
}

int Ejercicio::get_tiempo_estimado() {
	return this->tiempo_estimado;
} 

string Ejercicio::get_descripcion() {
	return this->descripcion;
}

int Ejercicio::get_ultima_semana() {
	return this->ultima_semana;
}

// Metodos setters
void Ejercicio::set_nombre(string nombre) {
	this->nombre = nombre;
}

void Ejercicio::set_tipo_ejercicio(string tipo_ejercicio) {
	this->tipo_ejercicio = tipo_ejercicio;
}

void Ejercicio::set_nivel_intensidad(string nivel_intensidad) {
	this->nivel_intensidad = nivel_intensidad;
}

void Ejercicio::set_tiempo_estimado(int tiempo_estimado) {
	this->tiempo_estimado = tiempo_estimado;
}

void Ejercicio::set_descripcion(string descripcion) {
	this->descripcion = descripcion;
}

void Ejercicio::set_ultima_semana(int ultima_semana) {
	this->ultima_semana = ultima_semana;
}

// Otros metodos

/*
	Ejercicio::mostrar() es un metodo propio de la clase ejercicio que se encarga
	de mostrar todos los atributos del objeto ejercicio y también es una función
	polimorfica, por lo que la veremos reflejadas en las clases derivadas.
*/
void Ejercicio::mostrar() {
	cout << endl << "###########################################################################################################" << endl << endl;
	cout << "Codigo del ejercicio: " << this->get_codigo_identificador() << endl;
	cout << "Nombre del ejercicio: " << this->get_nombre() << endl;
	cout << "El tipo del ejercicio: " << this->get_tipo_ejercicio() << endl;
	cout << "El nivel de intensidad: " << this->get_nivel_intensidad() << endl;
	cout << "El tiempo estimado para el ejercicio: " << this->get_tiempo_estimado() << "Min" << endl;
	cout << "La descripcion es: " << this->get_descripcion() << endl;
	cout << "La ultima semana de registro es: " << this->get_ultima_semana() << endl;
}

/*
	Ejercicio::filtrar(string tipo_ejercicio) se encarga de filtrar correctamente
	los valores de entrada que ingresa el usuario por consola, lo único que necesita
	saber es el tipo de ejercicio con el que se esta creando propiamente el objeto.
	
	filtrar también corresponde a una función polimorfica.
*/
void Ejercicio::filtrar(string tipo_ejercicio) {
	string nombre;
	string nivel_intensidad;
	int tiempo_estimado;
	string descripcion;
	int ultima_semana;
	
	char ops;
	
	// Usamos getline junto cin >> ws para limpiar el buffer de entrada y aceptar espacios.
	cout << endl << "Ingrese el nombre del ejercicio: ";
	getline(cin >> ws, nombre);
	
	cout << endl << "1. Nivel Basico" << endl;
	cout << "2. Nivel Intermedio" << endl;
	cout << "3. Nivel Avanzado" << endl;
	cout << "4. Nivel Alto Rendimiento" << endl;
	
	do {
		
		cin >> ops;
		
		// Cada nivel de intensidad esta asociado a una serie de repeticiones.
		switch (ops) {
			case '1': {
				nivel_intensidad = "Basico"; 	// Tipo
				tiempo_estimado = 2;			// Series
				break;
			}
			
			case '2': {
				nivel_intensidad = "Intermedio";
				tiempo_estimado = 4;
				break;
			}
			
			case '3': {
				nivel_intensidad = "Avanzado";
				tiempo_estimado = 5;
				break;
			}
			
			case '4': {
				nivel_intensidad = "Alto Rendimiento";
				tiempo_estimado = 6;
				break;
			}
			
			default: {
				cout << "Por favor, escoja una opcion entre 1 y 4." << endl;
			}
		}
		
	} while (ops != '1' && ops != '2' && ops != '3' && ops != '4');
	
	cout << endl << "Ingrese la descripcion del ejercicio: ";
	getline(cin >> ws, descripcion);
	
	cout << "Ingrese la ultima semana de uso del ejercicio: ";
	cin >> ultima_semana;
	
	// Setteamos todos los atributos correctamente filtrados.
	this->set_nombre(nombre);
	this->set_tipo_ejercicio(tipo_ejercicio);
	this->set_nivel_intensidad(nivel_intensidad);
	this->set_tiempo_estimado(tiempo_estimado);
	this->set_descripcion(descripcion);
	this->set_ultima_semana(ultima_semana);
}

/*
	Ejercicio::modificar() se encarga de mostrarle al usuario los correspondientes
	atributos que puede modificar una vez creado el objeto.
	
	modificar corresponde a una función polimorfica
*/
void Ejercicio::modificar() {
	char op;
	
	do {
		
		// Menú de opciones
		cout << endl << "###########################################################################################################" << endl << endl;
		cout << "Bienvenido a las modificaciones generales." << endl;
		cout << "1. Nombre del ejercicio." << endl;
		cout << "2. El nivel de intensidad." << endl;
		cout << "3. La descripcion." << endl;
		cout << "4. Salir." << endl << endl;
		
		cout << "Ingrese una opcion: ";
		cin >> op;
		
		switch (op) {
			// Bloque de opciones.
			case '1': {
				string nombre;
				
				cout << "Ingrese el nuevo nombre: ";
				getline(cin >> ws, nombre);
				
				this->set_nombre(nombre);
				
				break;
			}
			
			case '2': {
				char nivel;
				
				cout << "1. Nivel Basico" << endl;
				cout << "2. Nivel Intermedio" << endl;
				cout << "3. Nivel Avanzado" << endl;
				cout << "4. Nivel Alto Rendimiento" << endl;
				
				cout << "Ingrese el nuevo nivel de intensidad: ";
				
				do {
		
					cin >> nivel;
					
					/*
						Al modificar el nivel del ejercicio hay que modificar el tiempo que le corresponda,
						cada ejercicio tiene una serie de repeticiones y un tiempo en minutos por cada repetición.
					*/ 
					switch (nivel) {
						case '1': {
							nivel_intensidad = "Basico";
							tiempo_estimado = 2 * 45;
							break;
						}
						
						case '2': {
							nivel_intensidad = "Intermedio";
							tiempo_estimado = 4 * 45;
							break;
						}
						
						case '3': {
							nivel_intensidad = "Avanzado";
							tiempo_estimado = 5 * 45;
							break;
						}
						
						case '4': {
							nivel_intensidad = "Alto Rendimiento";
							tiempo_estimado = 6 * 45;
							break;
						}
						
						default: {
							cout << "Por favor, escoja una opcion entre 1 y 4." << endl;
						}
					}
					
				} while (nivel != '1' && nivel != '2' && nivel != '3' && nivel != '4');
				
				break;
			}
			
			case '3': {
				string descripcion;
				
				cout << "Ingrese la nueva descripcion: ";
				getline(cin >> ws, descripcion);
				
				this->set_descripcion(descripcion);
				
				break;
			}
			
			case '4': {
				// Salimos de las modificaciones generales propias de cualquier tipo de ejercicio.
				return;
			}
			
			default: {
				cout << "Por favor, ingrese una opcion entre 1 y 4." << endl;
			}

		}
		
	} while (true);
}

// ###############################################################################################################################################

// ################################################################# CLASE CARDIO ################################################################

// Constructor del ejercicio cardiovascular
Ejercicio_Cardiovascular::Ejercicio_Cardiovascular(

	int codigo_identificador,
	string nombre,
	string tipo_ejercicio,
	string nivel_intensidad,
	int tiempo_estimado,
	string descripcion,
	int ultima_semana,
	string tipo_maquina
	
) : Ejercicio(

	codigo_identificador,
	nombre,
	tipo_ejercicio,
	nivel_intensidad,
	tiempo_estimado,
	descripcion,
	ultima_semana
	
) {
	this->tipo_maquina = tipo_maquina;
}

// Metodos getters
string Ejercicio_Cardiovascular::get_tipo_maquina() {
	return this->tipo_maquina;
}

// Metodos setters
void Ejercicio_Cardiovascular::set_tipo_maquina(string tipo_maquina) {
	this->tipo_maquina = tipo_maquina;
}

// Otros metodos

/*
	Ejercicio_Cardiovascular::mostrar() utiliza como plantilla Ejercicio::mostrar(),
	por lo que lo único que le falta por mostrar son los atributos propios del ejercicio
	cardiovascular, en este caso el tipo de maquina.
*/
void Ejercicio_Cardiovascular::mostrar() {
	Ejercicio::mostrar();
	cout << "Tipo de maquina: " << this->get_tipo_maquina() << endl << endl;
	cout << "###########################################################################################################" << endl;
}

/*
	Ejercicio_Cardiovascular::filtrar(string tipo_ejercicio) utiliza como plantilla
	Ejercicio::filtrar(tipo_ejercicio), y en dicha función solo se asigno las repeticiones
	necesarias por el nivel, pero cada ejercicio en específico necesita un tiempo por
	cada repetición, en este caso en particular 45min por repetición.
	
	Además solo necesitamos filtrar el atributo propio del objeto ejercicio cardiovascular.
*/
void Ejercicio_Cardiovascular::filtrar(string tipo_ejercicio) {
	string tipo_maquina;
	int tiempo_estimado;
	
	Ejercicio::filtrar(tipo_ejercicio);
	
	tiempo_estimado = this->get_tiempo_estimado();
	tiempo_estimado *= 45;								// Minutos necesarios por repetición.
	
	this->set_tiempo_estimado(tiempo_estimado);
	
	cout << "Ingrese el tipo de maquina con el que se va a trabajar: ";
	getline(cin >> ws, tipo_maquina);
	
	this->set_tipo_maquina(tipo_maquina);				// settear el atributo ya filtrado.
	
	cout << endl << "###########################################################################################################" << endl;
}

/*
	Ejercicio_Cardiovascular::modificar() Utiliza como plantilla Ejercicio::modificar()
	y, en consecuencia, solo es necesario modificar correctamente los atributos propios 
	del tipo de ejercicio, en caso de futuras implementaciones, solo es necesario modificar
	esta función.
*/
void Ejercicio_Cardiovascular::modificar() {
	char op;
		
	Ejercicio::modificar();
	
	do {
		
		// Menú de modificaciones especifícas.
		cout << endl << "###########################################################################################################" << endl << endl;
		cout << "Bienvenido a las modificaciones especificas del ejercicio Cardiovascular." << endl;
		cout << "1. Tipo de maquina." << endl;
		cout << "2. Salir." << endl << endl;
		
		cout << "Ingrese una opcion: ";
		cin >> op;
		
		switch (op) {
			case '1': {
				string tipo_maquina;
				
				cout << "Ingrese la nueva descripcion: ";
				getline(cin >> ws, tipo_maquina);
				
				this->set_tipo_maquina(tipo_maquina);	// settear el atributo ingresado correctamente.
				
				break;
			}
			
			case '2': {
				// Salimos de las modificaciones generales propias del tipo de ejercicio.
				return;
			}				
				
			default: {
				cout << "Por favor, ingrese una de las opciones mostradas." << endl;
			}
		}
		
	} while (op != '2');
	
}

// ###############################################################################################################################################

// ################################################################# CLASE FUERZA ################################################################

// Constructor del ejercicio fuerza
Ejercicio_Fuerza::Ejercicio_Fuerza(

	int codigo_identificador,
	string nombre,
	string tipo_ejercicio,
	string nivel_intensidad,
	int tiempo_estimado,
	string descripcion,
	int ultima_semana,
	string grupo_muscular
	
) : Ejercicio(

	codigo_identificador,
	nombre,
	tipo_ejercicio,
	nivel_intensidad,
	tiempo_estimado,
	descripcion,
	ultima_semana
	
) {
	this->grupo_muscular = grupo_muscular;
}

// Metodos getters
string Ejercicio_Fuerza::get_grupo_muscular() {
	return this->grupo_muscular;
}

// Metodos setters
void Ejercicio_Fuerza::set_grupo_muscular(string grupo_muscular) {
	this->grupo_muscular = grupo_muscular;
}

// Otros metodos

/*
	Ejercicio_Fuerza::mostrar() utiliza como plantilla Ejercicio::mostrar(),
	por lo que lo único que le falta por mostrar son los atributos propios del ejercicio
	cardiovascular, en este caso el grupo muscular que se va a entrenar.
*/
void Ejercicio_Fuerza::mostrar() {
	Ejercicio::mostrar();
	cout << "Grupo muscular a trabajar: " << this->get_grupo_muscular() << endl << endl;
	cout << "###########################################################################################################" << endl;
}

/*
	Ejercicio_Fuerza::filtrar(string tipo_ejercicio) utiliza como plantilla
	Ejercicio::filtrar(tipo_ejercicio), y en dicha función solo se asigno las repeticiones
	necesarias por el nivel, pero cada ejercicio en específico necesita un tiempo por
	cada repetición, en este caso en particular 15min por repetición.
	
	Además solo necesitamos filtrar el atributo propio del objeto ejercicio de fuerza.
*/
void Ejercicio_Fuerza::filtrar(string tipo_ejercicio) {
	string grupo_muscular;
	int tiempo_estimado;
	
	Ejercicio::filtrar(tipo_ejercicio);
	
	tiempo_estimado = this->get_tiempo_estimado();
	tiempo_estimado *= 15;									// Minutos necesarios por repetición.
	
	this->set_tiempo_estimado(tiempo_estimado);
	
	cout << "Ingrese el grupo muscular que se va a entrenar: ";
	getline(cin >> ws, grupo_muscular);
	
	this->set_grupo_muscular(grupo_muscular);				// settear el atributo ya filtrado.
	
	cout << endl << "###########################################################################################################" << endl;
}

/*
	Ejercicio_Fuerza::modificar() Utiliza como plantilla Ejercicio::modificar()
	y, en consecuencia, solo es necesario modificar correctamente los atributos propios 
	del tipo de ejercicio, en caso de futuras implementaciones, solo es necesario modificar
	esta función.
*/
void Ejercicio_Fuerza::modificar() {
	char op;
		
	Ejercicio::modificar();
	
	do {
		
		// Menú de modificaciones especifícas.
		cout << endl << "###########################################################################################################" << endl << endl;
		cout << "Bienvenido a las modificaciones especificas del ejercicio Cardiovascular." << endl;
		cout << "1. Grupo muscular." << endl;
		cout << "2. Salir." << endl << endl;
		
		cout << "Ingrese una opcion: ";
		cin >> op;
		
		switch (op) {
			case '1': {
				string grupo_muscular;
				
				cout << "Ingrese el nuevo grupo muscular con el que se va a trabajar: ";
				getline(cin >> ws, grupo_muscular);
				
				this->set_grupo_muscular(grupo_muscular);		// settear el atributo ingresado correctamente.
				
				break;
			}
			
			case '2': {
				// Salimos de las modificaciones generales propias del tipo de ejercicio.
				return;
			}				
				
			default: {
				cout << "Por favor, ingrese una de las opciones mostradas." << endl;
			}
		}
		
	} while (op != '2');
	
}

// ###############################################################################################################################################

// ################################################################# CLASE COLECCION #############################################################

// Metodos getters
vector <Ejercicio*> Coleccion::get_coleccion() {
	return this->ejercicios;
}

// Metodos setters
void Coleccion::set_coleccion(Ejercicio* un_ejercicio) {
	this->ejercicios.push_back(un_ejercicio);
}

// Otros metodos

/*
	Los ejercicios se pueden eliminar según lo planteado en la problemática,
	por lo que es necesario también eliminar su existencia de la colección
	(vector) en donde se les referencia, para evitar tener punteros colgantes
	y que el programa se caíga.
	
	Por lo que borramos el ejercicio en base al indice que el usuario escoje.
*/
void Coleccion::eliminar_elemento(int indice) {
	delete ejercicios[indice];
	ejercicios.erase(ejercicios.begin() + indice);
}

/*
	El problema planteado solicita mostrar una serie de ejercicios que pertenezcan
	a cierto nivel de intensidad que el usuario ingresa por pantalla, por lo que
	la función en base a ese nivel (que tiene como parámetro) realiza un bucle foreach
	y verficia si el nivel de los ejercicios en la colección corresponde al nivel.
*/
void Coleccion::mostrar_ejercicio_tipo_nivel(string nivel_intensidad) {
	// Enumerador simple.
	int cont = 0;
	
	cout << endl;

	// Bucle Foreach.
	for (auto ejercicio : this->get_coleccion()) {
		// Verificamos si el ejercicio corresponde al nivel parámetrizado.
		if (ejercicio->get_nivel_intensidad() == nivel_intensidad) {
			cont++;
			
			cout << cont << ". Nombre: " << ejercicio->get_nombre() << ", Tiempo estimado: " << ejercicio->get_tiempo_estimado() << "Min, Tipo de ejercicio: " << ejercicio->get_tipo_ejercicio() << endl;
		}
		
	}
	
	// En caso de no encontrar ejercicio del nivel parámetrizado se le avisa al usuario.
	if (cont == 0) {
		cout << "No hay ejercicios del tipo: " << nivel_intensidad << " registrados." << endl;
	}
}

/*
	Coleccion::filtrador() se encarga de entregar el indice del ejercicio con el que el usuario
	desea trabajar según sea el fin conveniente, el fin de esta función es poder escoger el ejercicio
	que se quiere por ejemplo, mostrar, eliminar o modificar.
*/
int Coleccion::filtrador() {
	// Enumerador simple.
	int cont = 0;
	int indice;
	
	// Bucle foreach con el menú de opciones de ejercicios.
	for (auto ejercicio : this->get_coleccion()) {
		cont ++;
		
		cout << cont << ". Nombre: " << ejercicio->get_nombre() << ", ID: " << ejercicio->get_codigo_identificador() << ", Tipo de ejercicio: " << ejercicio->get_tipo_ejercicio() << endl;
	}
	
	// Sección en donde el usuario escoje el ejercicio
	do {
		cout << endl << "Escoja una opcion con la que trabajar: ";
		cin >> indice;
		
		// Verificamos que el indice es posible en el vector y es positivo.
		if (this->get_coleccion().size() < indice || indice <= 0) {
			cout << "Por favor, ingrese una de las opciones mostradas." << endl;
		}
		
	} while (this->get_coleccion().size() < indice || indice <= 0);
	
	return indice;
}

// ################################################################## CLASE RUTINA ###############################################################

// Destructor
Rutina::~Rutina() {
	for (auto ejercicio : ejercicios) {
		delete ejercicio;
	}
	
	ejercicios.clear();
}

// Metodos getters
vector <Ejercicio*> Rutina::get_ejercicios() {
	return this->ejercicios;
}

string Rutina::get_cliente() {
	return this->cliente;
}

int Rutina::get_tiempo_total() {
	return this->tiempo_total;
}

// Metodos setters
void Rutina::set_ejercicios(Ejercicio* un_ejercicio) {
	this->ejercicios.push_back(un_ejercicio);
}

void Rutina::set_cliente(string un_cliente) {
	this->cliente = un_cliente;
}

void Rutina::set_tiempo_total(int tiempo_total) {
	this->tiempo_total += tiempo_total;
}

// ########################################################## CLASE COLECCION RUTINAS ############################################################

// Destructor
Coleccion_rutina::~Coleccion_rutina() {
	for (auto rutina : rutinas) {
		delete rutina;
	}
	
	rutinas.clear();
}

// Metodos getters
vector <Rutina*> Coleccion_rutina::get_coleccion_rutina() {
	return this->rutinas;
}

// Metodos setters
void Coleccion_rutina::set_coleccion_rutina(Rutina* una_rutina) {
	this->rutinas.push_back(una_rutina);
}

// ############################################################# CLASE ORQUESTADOR ###############################################################

/*
	Orquestador::menu_principal() se encarga de mostrar la interfaz gráfica
	del menú principal o primer menú que el usuario ve por pantalla.
*/
void Orquestador::menu_principal() {
	cout << endl << "############################################# CENTRO DEPORTIVO ############################################" << endl << endl;
	cout << "1. Crear un ejercicio" << endl;
	cout << "2. Actualizar un ejercicio" << endl;
	cout << "3. Eliminar un ejercicio" << endl;
	cout << "4. Consultar informacion de un ejercicio" << endl;
	cout << "5. Buscar ejercicios segun el nivel de intensidad" << endl;
	cout << "6. Generar una rutina de entrenamiento" << endl;
	cout << "7. Salir del programa" << endl << endl;
	cout << "##########################################################################################################" << endl << endl;
}

/*
	Orquestador::pedir_intensidad() se encarga de filtrar y devolver el nivel
	de intensidad con el que el usuario quiere trabajar, ahorrado lineas de código
	ya que se pide en reiteradas ocaciones a lo largo del programa.
*/
string Orquestador::pedir_intensidad() {
    char op;
    string niveles[] {"Basico", "Intermedio", "Avanzado", "Alto Rendimiento"};

	// Menú de opciones
    cout << endl << "###########################################################################################################" << endl << endl;
	cout << "1. Basico." << endl;
	cout << "2. Intermedio." << endl;
	cout << "3. Avanzado." << endl;
	cout << "4. Alto Rendimiento." << endl;

	// Sección de selección y filtro.
    do {

		cout << "Ingrese el nivel de intensidad con el que se desea trabajar: ";
		cin >> op;

        if (op >= '1' && op <= '4') {
        	// Se le resta '0' para obtener su valor númerico ya que op es un char.
            return niveles[op - '0' - 1];
        }

        cout << "Opcion invalida\n";
    } while (true);
}

/*
	Orquestador::ejercicios_disponibles(Coleccion* ejercicios, Coleccion_rutina* rutinas, int semana, string cliente)
	se encarga de devolver un subconjunto de la colección de ejercicios de la base de datos principal, considerando si
	el cliente ingresado por el usuario realizo ejercicios la semana anterior del registro de la rutina para descartar
	dichos ejercicios y dejar el resto.
*/
Coleccion* Orquestador::ejercicios_disponibles(Coleccion* ejercicios, Coleccion_rutina* rutinas, int semana, string cliente) {
	// Subconjunto de la base de datos principal.
	Coleccion* ejercicios_disponibles = new Coleccion();
	// Ejercicios eliminados para el Subconjunto.
	vector <Ejercicio*> ejercicios_prohibidos;
	
	// Bucle foreach que verifica los ejercicios utilizados por el cliente la semana pasada.
	for (auto rutina : rutinas->get_coleccion_rutina()) {	
		if (rutina->get_cliente() == cliente && rutina->get_ejercicios()[0]->get_ultima_semana() == semana - 1) {
			// Sección donde agregamos los ejercicios descartados para el cliente.
			ejercicios_prohibidos = rutina->get_ejercicios();
			break;
			
		}
	}
	
	// Bucle foreach donde setteamos el subconjunto con los ejercicios disponibles
	for (auto ejercicio : ejercicios->get_coleccion()) {
		bool prohibido = false;
		
		// Bucle foreach en donde identificamos el ejercicio descartado.
		for (auto ejercicio_prohibido : ejercicios_prohibidos) {
			if (ejercicio->get_codigo_identificador() == ejercicio_prohibido->get_codigo_identificador()) {
				// Decimos que no podemos escojer dicho ejercicio.
				prohibido = true;
				break;
			}
		}
		
		// Si el ejercicio se puede escojer, osea prohibido = false lo setteamos al subconjunto
		if (!prohibido) {
			ejercicios_disponibles->set_coleccion(ejercicio);
		}
	}
	
	// Retornados el Subconjunto.
	return ejercicios_disponibles;
}

/*
	Orquestador::coordinador() es la función que contiene la lógica principal del programa,
	es quién se encarga de realizar todas las acciones que el usuario puede realizar por el programa.
*/
void Orquestador::coordinador() {
	char op;
	int codigo = 1;

	// Creación de las colecciones que guardan los ejercicios y rutinas.
	Coleccion* v_ejercicios = new Coleccion();
	Coleccion_rutina* v_rutinas = new Coleccion_rutina();
	
	do {
		
		menu_principal();
		cin >> op;
		
		switch (op) {
			// Crear un ejercicio
			case '1': {
				char tipo_ejercicio;
				
				// Menú de los ejercicios que se pueden crear.
				cout << endl << "###########################################################################################################" << endl << endl;
				cout << "1. Ejercicio Cardiovascular" << endl;
				cout << "2. Ejercicio de Fuerza" << endl;
				
				do {
					
					cin >> tipo_ejercicio;
					
					switch (tipo_ejercicio) {
						case '1': {
							// Instanciamos el objeto en su forma básica.
							Ejercicio_Cardiovascular* jc = new Ejercicio_Cardiovascular(codigo, "NaN", "NaN", "NaN", 0, "NaN", 0, "NaN");
							// Setteamos los valores correctamente con filtrar.
							jc->filtrar("Cardiovascular");
							// Agregamos el ejercicio a la colección de ejercicios.
							v_ejercicios->set_coleccion(jc);
							// Dejamos el código aumentado para el próximo ejercicio que se cree.
							codigo++;
							
							cout << endl << "Ejercicio registrado correctamente!" << endl;
							break;
						}						
						
						case '2': {
							// Instanciamos el objeto en su forma básica.
							Ejercicio_Fuerza* jf = new Ejercicio_Fuerza(codigo, "NaN", "NaN", "NaN", 0, "NaN", 0, "NaN");
							// Setteamos los valores correctamente con filtrar.
							jf->filtrar("Fuerza");
							// Agregamos el ejercicio a la colección de ejercicios.
							v_ejercicios->set_coleccion(jf);
							// Dejamos el código aumentado para el próximo ejercicio que se cree.
							codigo++;
							
							cout << endl << "Ejercicio registrado correctamente!" << endl;
							break;
						}
						
						default: {
							cout << "Por favor, ingrese una opcion entre 1 y 2." << endl;
						}
					}
					
				} while (tipo_ejercicio != '1' && tipo_ejercicio != '2');
				
				break;
			}
			
			// Actualizar un ejercicio
			case '2': {
				
				// Verificamos que existen ejercicios registrados.
				if (!v_ejercicios->get_coleccion().empty()) {
					// Obtenemos el indice del ejercicio que deseamos modificar.
					int indice = v_ejercicios->filtrador();
					
					// Modificamos dicho ejercicio.
					v_ejercicios->get_coleccion()[indice - 1]->modificar();
				}
				
				else {
					cout << "No hay ejercicios registrados." << endl;
				}
				
				break;
			}
			
			// Eliminar un ejercicio
			case '3': {
				
				// Verificamos que existen ejercicios registrados.
				if (!v_ejercicios->get_coleccion().empty()) {
					// Obtenemos el indice del ejercicio que deseamos eliminar.
					int indice = v_ejercicios->filtrador();
					
					// Eliminamos dicho ejercicio.
					v_ejercicios->eliminar_elemento(indice - 1);
					
				}
				
				else {
					cout << "No hay ejercicios registrados." << endl;
				}
				
				break;
			}
			
			// Consultar informacion de un ejercicio
			case '4': {
				
				// Verificamos que existen ejercicios registrados.
				if (!v_ejercicios->get_coleccion().empty()) {
					// Obtenemos el indice del ejercicio que deseamos visualizar.
					int indice = v_ejercicios->filtrador();
					
					// Mostramos dicho ejercicio.		
					v_ejercicios->get_coleccion()[indice - 1]->mostrar();
				}
				
				else {
					cout << "No hay ejercicios registrados." << endl;
				}

				break;
			}
			
			// Buscar ejercicios segun el nivel de intensidad
			case '5': {
				string nivel;
				
				// Verificamos que existen ejercicios registrados.
				if (!v_ejercicios->get_coleccion().empty()) {
					// Solitamos los ejercicios que queremos ver en base a su nivel,
					nivel = pedir_intensidad();
					// Mostramos los ejercicios en base al nivel elejido.
					v_ejercicios->mostrar_ejercicio_tipo_nivel(nivel);
				}
				
				else {
					cout << "No hay ejercicios registrados." << endl;
				}
				
				break;
			}
			
			// Generar una rutina de entrenamiento
			case '6': {
				// Creamos una nueva rutina.
				Rutina* rutina = new Rutina();
				// Creamos el subconjunto de ejercicios disponibles.
				Coleccion* v_ejercicios_aux = new Coleccion();
				
				/*
					Solicitamos:
						- la cantidad de ejercicios.
						- la semana de registro
						- El ID del Cliente.
					Y con esa información podemos crear la rutina.
				*/
				int cant_ejercicios;
				int contador;
				string nivel;
				int semana;
				string id_cliente;
				
				contador = 0;
				
				// Verificamos que existen ejercicios registrados.
				if (!v_ejercicios->get_coleccion().empty()) {
					cout << "Ingrese la cantidad de ejercicios que quiere usar para la rutina de entrenamiento: ";
					cin >> cant_ejercicios;
					
					cout << "Ingrese la semana en la que se realizara esta rutina de entrenamiento: ";
					cin >> semana;
					
					cout << "Ingrese la ID del cliente asociado a la rutina: ";
					getline(cin >> ws, id_cliente);
					
					
					// Verificamos si existen rutinas creadas.
					if (!v_rutinas->get_coleccion_rutina().empty()) {
						// Creamos el subconjunto de ejercicios disponibles para un cliente en específico.
						v_ejercicios_aux = ejercicios_disponibles(v_ejercicios, v_rutinas, semana, id_cliente);
					}
					
					// En caso de que no se han creado rutinas nunca, el subconjunto es igual al conjunto original.
					else {
						v_ejercicios_aux = v_ejercicios;
					}
					
					// Verificamos si el subconjunto de ejercicios es capaz de satisfacer la rutina.
					if (v_ejercicios_aux->get_coleccion().size() >= cant_ejercicios) {
						// Le solitamos al usuario que tipo de intensidad desea para su rutina.
						nivel = pedir_intensidad();
						
						// Recorremos el subconjunto de ejercicios con un bucle foreach
						for (auto ejercicio : v_ejercicios_aux->get_coleccion()) {
							// Filtramos por el nivel de intensidad hasta satisfacer la cantidad de ejercicios requeridos.
							if (ejercicio->get_nivel_intensidad() == nivel && contador < cant_ejercicios) {
								contador++;
								
								// Creamos una copia del ejercicio a settear para evitar punteros colgantes
								auto ejercicio_aux = *ejercicio;
								auto *ej = new auto(ejercicio_aux);
								
								// Modificamos la semana de uso.
								ej->set_ultima_semana(semana);
								// Setteamos el ejercicio para la rutina.
								rutina->set_ejercicios(ej);
								// Setteamos el cliente asociado a la rutina.
								rutina->set_cliente(id_cliente);
								// Setteamos el tiempo necesario para la rutina.
								rutina->set_tiempo_total(ej->get_tiempo_estimado()); 
										
							}
						}
						
						// En caso de poder satisfacer la cantidad de ejercicios le mostramos al usuario la rutina creada.
						if (contador == cant_ejercicios) {
							cout << endl << "###########################################################################################################" << endl << endl;
							cout << "ID Del cliente asociado: "<< rutina->get_cliente() << endl;
							cout << endl << "Ejercicios asociados: " << endl;
							
							for (auto ejercicio : rutina->get_ejercicios()) {
								cout << "Nombre: " << ejercicio->get_nombre() << ", Tiempo estimado: " << ejercicio->get_tiempo_estimado() << "Min, Tipo de ejercicio: " << ejercicio->get_tipo_ejercicio() << endl;	
							}
							
							cout << endl << "Tiempo total para realizar la rutina: "<< rutina->get_tiempo_total() << "Min." << endl;
							cout << endl << "###########################################################################################################" << endl << endl;
							
							cout << "Rutina creada correctamente!" << endl;
							
							// Setteamos la rutina en la colección.
							v_rutinas->set_coleccion_rutina(rutina);
						}
						
						// De caso contrario no se registra dicha rutina en la colección de rutinas.
						else {
							cout << "No hay los suficientes ejercicios para satisfacer la rutina deseada." << endl;
						}
						
					}
					
					else {
						cout << "No hay los suficientes ejercicios para satisfacer la rutina deseada." << endl;
					}
				}
				
				else {
					cout << "No hay ejercicios registrados." << endl;
				}
				
				break;
			}
				
			case '7': {
				// Borramos todos los datos para no tener problemas de memoria.
				delete v_ejercicios;
				delete v_rutinas;
				
				cout << "Saliendo del programa..." << endl;
				
				break;
			}
				
			default: {
				cout << "Por favor, escoja una opción entre el 1 y el 7." << endl;
			}
			
		}
		
	} while (op != '7');
	
}
