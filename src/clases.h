#include <iostream>
#include <vector>

using namespace std;

class Ejercicio {
	private:
		int codigo_identificador;
		string nombre;
		string tipo_ejercicio;
		string nivel_intensidad;
		int tiempo_estimado;
		string descripcion;
		int ultima_semana;
		
	public:
		// Constructor
		Ejercicio(
			int codigo_identificador,
			string nombre,
			string tipo_ejercicio,
			string nivel_intensidad,
			int tiempo_estimado,
			string descripcion,
			int ultima_semana
		);
		
		// Destructor
		~Ejercicio();
		
		// Metodos getters
		int get_codigo_identificador();
		string get_nombre();
		string get_tipo_ejercicio();
		string get_nivel_intensidad();
		int get_tiempo_estimado();
		string get_descripcion();
		int get_ultima_semana();
		
		// Metodos setters
		void set_nombre(string nombre);
		void set_tipo_ejercicio(string tipo_ejercicio);
		void set_nivel_intensidad(string nivel_intensidad);
		void set_tiempo_estimado(int tiempo_estimado);
		void set_descripcion(string descripcion);
		void set_ultima_semana(int ultima_semana);
		
		// Otros metodos
		virtual void mostrar();
		virtual void filtrar(string tipo_ejercicio);
		virtual void modificar();
};

class Ejercicio_Cardiovascular : public Ejercicio {
	private:
		string tipo_maquina;
		
	public:
		Ejercicio_Cardiovascular(
			int codigo_identificador,
			string nombre,
			string tipo_ejercicio,
			string nivel_intensidad,
			int tiempo_estimado,
			string descripcion,
			int ultima_semana,
			string tipo_maquina
		);
		
		// Metodos getters
		string get_tipo_maquina();
		
		// Metodos setters
		void set_tipo_maquina(string tipo_maquina);
		
		// Otros metodos
		void mostrar();
		void filtrar(string tipo_ejercicio);
		void modificar();
};

class Ejercicio_Fuerza : public Ejercicio {
	private:
		string grupo_muscular;
		
	public:
		// Constructor
		Ejercicio_Fuerza(
			int codigo_identificador,
			string nombre,
			string tipo_ejercicio,
			string nivel_intensidad,
			int tiempo_estimado,
			string descripcion,
			int ultima_semana,
			string grupo_muscular
		);
		
		// Metodos getters
		string get_grupo_muscular();
		
		// Metodos setters
		void set_grupo_muscular(string grupo_muscular);
		
		// Otros metodos
		void mostrar();
		void filtrar(string tipo_ejercicio);
		void modificar();
};

class Coleccion {
	private:
		vector <Ejercicio*> ejercicios;
		
	public:
		// Metodos getters
		vector <Ejercicio*> get_coleccion();
		
		// Metodos setters
		void set_coleccion(Ejercicio* un_ejercicio);
		
		// Otros metodos
		void eliminar_elemento(int indice);
		void mostrar_ejercicio_tipo_nivel(string nivel_intensidad);
		int filtrador();
};

class Rutina {
	private:
		vector <Ejercicio*> ejercicios;
		string cliente;
		int tiempo_total;
		
	public:
		// Destructor
		~Rutina();
		
		// Metodos getters
		vector <Ejercicio*> get_ejercicios();
		string get_cliente();
		int get_tiempo_total();
		
		// Metodos setters
		void set_ejercicios(Ejercicio* un_ejercicio);
		void set_cliente(string un_cliente);
		void set_tiempo_total(int tiempo_total);
};

class Coleccion_rutina {
	private:
		vector <Rutina*> rutinas;
		
	public:
		// Destructor
		~Coleccion_rutina();
		
		// Metodo getters
		vector <Rutina*> get_coleccion_rutina();
		
		// Metodo setters
		void set_coleccion_rutina(Rutina* una_rutina);		
};

class Orquestador {
	public:
		void menu_principal();
		string pedir_intensidad();
		Coleccion* ejercicios_disponibles(Coleccion* ejercicios, Coleccion_rutina* rutinas, int semana, string cliente);
		void coordinador();
};
