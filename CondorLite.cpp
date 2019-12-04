#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

struct loggin{
	   char user[50];
	   char password[50];
	   char confirPass[50];
	   char ident[50];
	   char cod[50];
};

struct captNotas{
	   
	   char elegMater[50];
	   char codEstud[50];
	   float notaCant;
	   double notasN;
	   float promed;  
};

struct modNotas{
	   
	   char curso[50];
	   char codEstud[50];
	   int modNota;
};

struct elimNotas{
	   
	   char curso[50];
	   char codEstud[50];
	   int elimNota;
};

struct Estudiante{
	   char Nombre[50];
	   char Apellido[50];	   
	   char Sexo[50];
	   char Ident[50];
	   char CodEst[50];
	   char Carrera[50];
	   char Semestre[50];
};

struct Profesor{
     char Codigo[50];
     char Nombre[50];
     char Apellido[50];
     char Materia[50];
};

struct Materia{
     char Codigo[50];
     char Nombre[50];
};


struct loggin log;
struct Estudiante Estud;
struct Profesor Prof;
struct Materia Mater;
struct captNotas capNotas;
struct modNotas editNotas;
struct elimNotas delNotas;


ofstream Aprendiz;
ofstream Maestro;
ofstream Asignatura;
ofstream capturaNota;
ofstream modificNotas;
ofstream eliminNotas;
ofstream dateBaseLog;

int main();
void Loggin();

// ----------------------------Inicio Menus  -------------------------
int salir(){
	int slr=0;
	
	cout<<"Quiere salir [Si/(cualquier tecla)]-[No/0 (Menu CondorLite)]?"<<endl;
	cin>>slr;
	
	if(slr == 0){
		system("cls");
		main();
	}else{
		system("cls");
	 	cout<<"			<<<Hasta Luego>>>"<<endl;
	 	getch();
	 	exit(0);
	}
}

int menuPrimario(int opc){
		system("cls");
		cout<<"			Menu Principal Administrador			"<<endl;
		cout<<"1- Estudiantes  " <<endl;
		cout<<"2- Profesores   "<<endl;
		cout<<"3- Materias "<<endl;
		cout<<"4- Salir  "<<endl;
		
		cin>>opc;
		return opc;
}

int menuSecundario(int opc){
		system("cls");
		cout<<"			Menu Gestion Administrador			"<<endl;
		cout<<"1- Crear  " <<endl;
		cout<<"2- Modificar   "<<endl;
		cout<<"3- Eliminar "<<endl;
		cin>>opc;
		return opc;
}

int menuOpcAdministrador(int opc){
		
		system("cls");
		cout<<"			  Administradores			"<<endl;
		cout<<"1- Opciones de Administrador  " <<endl;
		cout<<"2- Registro de Administrador   "<<endl;
		cout<<"3- Salir  "<<endl;
		
		cin>>opc;
		system("cls");
		return opc;
}

int menuLoggin(int opc){
		system("cls");
		cout<<"			 CondorLite			"<<endl;
		cout<<"1- Estudiantes  " <<endl;
		cout<<"2- Profesores   "<<endl;
		cout<<"3- Administradores  "<<endl;
		cout<<"4- Salir  "<<endl;
		
		cin>>opc;
		system("cls");
		return opc;
		
}

int menuProfesor(int opc){
		system("cls");
		cout<<"			Menu Principal Profesor			"<<endl;
		cout<<"1- Capturar Notas  " <<endl;
		cout<<"2- Modificar Notas   "<<endl;
		cout<<"3- Eliminar Notas "<<endl;
		cin>>opc;
		system("cls");
		return opc;
}

int menuEstudiantes(int opc){
		system("cls");
		cout<<"			 Menu Principal Estudiantes			"<<endl;
		cout<<"1- Ver Notas  " <<endl;
		cout<<"2- Salir de Condor "<<endl;		
		cin>>opc;
		
		system("cls");
		return opc;
}
// ----------------------------Fin Menus  -------------------------

// ----------------------------Inicio Opciones Administrador -------------------------
// ----------------------------Inicio Menu Administrador - Estudiantes -------------------------
void crearEstudiante(){
		system("cls");
		Aprendiz.open("EstudiantesUD.txt", ios::out | ios::app);
		dateBaseLog.open("BaseDatosLogginUD.txt", ios::out |ios::app);
		
		if(Aprendiz.fail() || dateBaseLog.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   		}else{
			 int repet=1;
			 cout<<"1- Crear Estudiante " <<endl;
			 cout<<"Digite el numero de identificacion/cedula del Estudiante"<<endl;
	 	     cin>>log.user;
			 cout<<"Digite el Nombre "<<endl;
			 cin>> Estud.Nombre;
			 cout<<"Digite el Apellido "<<endl;
			 cin>> Estud.Apellido;
			 cout<<"Digite el Sexo "<<endl;
			 cin>> Estud.Sexo;
			 cout<<"Digite el Tarjeta de Identidad / Cedula "<<endl;
			 cin>> Estud.Ident;
			 cout<<"Digite el Codigo Estudiantil "<<endl;
			 cin>> Estud.CodEst;
			 cout<<"Digite el Carrera "<<endl;
			 cin>> Estud.Carrera;
			 cout<<"Digite el Semestre "<<endl;
			 cin>> Estud.Semestre;
			 do{
			 	cout<<"Digite la contrasena"<<endl;
	 	     	cin>>log.password;
	 	     	cout<<"confirme la contrasena"<<endl;
	 	     	cin>>log.confirPass;
	 	     	repet = strcmp(log.password,log.confirPass);
	 	     	if(repet == 0){
	 	     		cout<<"La contraseña coinciden, click para continuar"<<endl;
	 	     		getch();
			  	}else{
			  		cout<<"La contrasena no coinciden, vuelva a ingresar la contrasena"<<endl;
			  	}	 	     
	 	 	}while(repet != 0);
			 
			 Aprendiz<<endl<<Estud.Nombre<<" "<<Estud.Apellido<<" "<<Estud.Sexo<<" "<<Estud.Ident<<" "<<Estud.CodEst<<" "<<Estud.Carrera<<" "<<Estud.Semestre<<endl;
			 dateBaseLog << log.user <<" "<<  Estud.CodEst << " "<< log.password << " " << log.confirPass << " " << "Estud" <<endl;
	 	   	 cout<<"El usuario fue registrado exitosamente "<<endl<<endl;
	 }
	 Aprendiz.close();
	 dateBaseLog.close();  
}

void cambioContraEstud(char codigo[30]){
	dateBaseLog.close();
		int b=1;
		int repet=1;
		
		ifstream dateBaseLog;
		dateBaseLog.open("BaseDatosLogginUD.txt", ios::in);
		
	  	ofstream modiDBL;
		modiDBL.open("ModBaseDatosUD.txt", ios::out);
		
	if(dateBaseLog.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   	}else{
			   
			   dateBaseLog>>log.user;
			   while(!dateBaseLog.eof()){
			   dateBaseLog>>log.cod>>log.password>>log.confirPass>>log.ident;
				b = strcmp(log.cod,codigo);
					
				if(b == 0){	
			    cout<<"Digite el numero de identificacion/cedula del Estudiante"<<endl;
	 	   		cin>>log.user;
	 	   		do{
			 			cout<<"Digite la contrasena"<<endl;
	 	     			cin>>log.password;
	 	     			cout<<"confirme la contrasena"<<endl;
	 	     			cin>>log.confirPass;
	 	     			repet = strcmp(log.password,log.confirPass);
	 	     			
	 	     			if(repet == 0){
	 	     				cout<<"La contraseña coinciden, click para continuar"<<endl;
	 	     				getch();
			  			}else{
			  				cout<<"La contrasena no coinciden, vuelva a ingresar la contrasena"<<endl;
			  			}	 	  
						     
	 	 		}while(repet != 0);
	 	   		     modiDBL << log.user <<" "<< codigo << " "<< log.password << " " << log.confirPass << " " << log.ident <<endl;
	 	   		b=1;
	 	   		}else{
	 	   		     modiDBL << log.user <<" "<< log.cod << " "<< log.password << " " << log.confirPass << " " << log.ident <<endl;
	 	   		}
	 	   		dateBaseLog>>log.user;
			}
			
			dateBaseLog.close();
			modiDBL.close();
			 
    		remove("BaseDatosLogginUD.txt");
    		rename("ModBaseDatosUD.txt","BaseDatosLogginUD.txt");
	 }
}

void modificarEstud(){
		system("cls");
		ifstream Aprendiz;
		Aprendiz.open("EstudiantesUD.txt", ios::in);
		
		ofstream modif_estud;
		modif_estud.open("ModEstudiantesUD.txt", ios::out);
		
		
		if(Aprendiz.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   }else{
			 int a=0;
			 char codigo[15];
			 
			 
			 cout<<"Digite el codigo del estudiante que desea modificar "<<endl;
			 cin>>codigo;
			 
			 Aprendiz >>Estud.Nombre;
			 
					while(!Aprendiz.eof()){
					Aprendiz>>Estud.Apellido>>Estud.Sexo>>Estud.Ident>>Estud.CodEst>>Estud.Carrera>>Estud.Semestre;		 
					a = strcmp(codigo,Estud.CodEst);
					if(a == 0){
			 			cout<<"Digite los nuevos datos del estudiante "<<Estud.CodEst<<endl;
			 			cout<<"Digite el Nombre "<<endl;
			 			cin>> Estud.Nombre;
			 			cout<<"Digite el Apellido "<<endl;
			 			cin>> Estud.Apellido;
						cout<<"Digite el Sexo "<<endl;
			 			cin>> Estud.Sexo;
			 			cout<<"Digite el Tarjeta de Identidad / Cedula "<<endl;
			 			cin>> Estud.Ident;
			 			cout<<"Digite el Codigo Estudiantil "<<endl;
			 			cin>> Estud.CodEst;
			 			cout<<"Digite el Carrera "<<endl;
			 			cin>> Estud.Carrera;
			 			cout<<"Digite el Semestre "<<endl;
			 			cin>> Estud.Semestre;
			 			cout<<"Los datos han sido modificados "<<endl;
			 			modif_estud<<Estud.Nombre<<" "<<Estud.Apellido<<" "<<Estud.Sexo<<" "<<Estud.Ident<<" "<<Estud.CodEst<<" "<<Estud.Carrera<<" "<<Estud.Semestre<<endl;
			 
					}else{
						
						modif_estud<<Estud.Nombre<<" "<<Estud.Apellido<<" "<<Estud.Sexo<<" "<<Estud.Ident<<" "<<Estud.CodEst<<" "<<Estud.Carrera<<" "<<Estud.Semestre<<endl;
			 		}		 		
			 				 		
					Aprendiz >>Estud.Nombre;
			 }
			 Aprendiz.close();
			 modif_estud.close();
			 cambioContraEstud(codigo);
			 remove("EstudiantesUD.txt");
       		 rename("ModEstudiantesUD.txt","EstudiantesUD.txt");
       		 
       		 
	 }
}

void elimnContraEstud(char codigo[30]){
	dateBaseLog.close();
		int b=1;
		int repet=1;
		
		ifstream dateBaseLog;
		dateBaseLog.open("BaseDatosLogginUD.txt", ios::in);
		
	  	ofstream modiDBL;
		modiDBL.open("ModBaseDatosUD.txt", ios::out);
		
	if(dateBaseLog.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   	}else{
			   
			   dateBaseLog>>log.user;
			   while(!dateBaseLog.eof()){
			   dateBaseLog>>log.cod>>log.password>>log.confirPass>>log.ident;
				b = strcmp(log.cod,codigo);
					
				if(b == 0){	
	 	   		do{
	 	   				cout<<"Digite la contraseña para borrar la informacion"<<endl;
			 			cout<<"Digite la contrasena"<<endl;
	 	     			cin>>log.password;
	 	     			cout<<"confirme la contrasena"<<endl;
	 	     			cin>>log.confirPass;
	 	     			repet = strcmp(log.password,log.confirPass);
	 	     			
	 	     			if(repet == 0){
	 	     				cout<<"La contraseña coinciden, click para continuar"<<endl;
	 	     				getch();
			  			}else{
			  				cout<<"La contrasena no coinciden, vuelva a ingresar la contrasena"<<endl;
			  			}	 	  
						     
	 	 		}while(repet != 0);
					 cout<<"La base de datos fue actualizada, se ha borrado la informacion "<<endl;
	 	   			 b=1;
	 	   		}else{
	 	   		     modiDBL << log.user <<" "<< log.cod << " "<< log.password << " " << log.confirPass << " " << log.ident <<endl;
	 	   		}
	 	   		dateBaseLog>>log.user;
			}
			
			dateBaseLog.close();
			modiDBL.close();
			 
    		remove("BaseDatosLogginUD.txt");
    		rename("ModBaseDatosUD.txt","BaseDatosLogginUD.txt");
	 }
}

void eliminEstud(){
		system("cls");
		ifstream Aprendiz;
		Aprendiz.open("EstudiantesUD.txt", ios::in);
		
		ofstream elimEstud;
		elimEstud.open("ElimEstudiantesUD.txt", ios::out);
		
		
		if(Aprendiz.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   }else{
			 int a=0;
			 int i=0;
			 char codigo[15];
			 
			 
			 cout<<"Digite el codigo del estudiante que desea eliminar "<<endl;
			 cin>>codigo;
			 
			 Aprendiz >>Estud.Nombre;
			 
					while(!Aprendiz.eof()){
					Aprendiz>>Estud.Apellido>>Estud.Sexo>>Estud.Ident>>Estud.CodEst>>Estud.Carrera>>Estud.Semestre;		 
					a = strcmp(codigo,Estud.CodEst);
					if(a == 0){
			 			cout<<"Los datos del estudiante "<<Estud.CodEst<<" fueron eliminados "<<endl;
			 			i++;
			 		}else{
						if(a != 0){
							 cout<<"No se encontraron los datos del estudiante "<<Estud.CodEst<<endl;
							 i++;
					 	}
						elimEstud<<Estud.Nombre<<" "<<Estud.Apellido<<" "<<Estud.Sexo<<" "<<Estud.Ident<<" "<<Estud.CodEst<<" "<<Estud.Carrera<<" "<<Estud.Semestre<<endl;
			 		}		 			
					Aprendiz >>Estud.Nombre;
			 }
			 if(i == 0){
 	  		 	  cout<<"No se encontro la materia "<<endl;
			 }else{
			 	   cout<<"La base de datos se ha actualizado"<<endl;
             }
			 Aprendiz.close();
			 elimEstud.close();
			 elimnContraEstud(codigo);
			 remove("EstudiantesUD.txt");
       		 rename("ElimEstudiantesUD.txt","EstudiantesUD.txt");     		 
	 
	 }
}
// ----------------------------Fin Menu Administrador - Estudiantes -------------------------


// ----------------------------Inicio Menu Administrador - Profesores -------------------------
void crearProfe(){
		system("cls");
		Maestro.open("ProfesoresUD.txt", ios::out | ios::app);
		dateBaseLog.open("BaseDatosLogginUD.txt", ios::out |ios::app);
		
		if(Maestro.fail() || dateBaseLog.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   		}else{
			 int repet=1;
			 system("cls");
			 cout<<"1- Crear Profesor " <<endl;
		
			 cout<<"Digite el numero de identificacion/cedula del Profesor"<<endl;
	 	     cin>>log.user;
			 cout<<"Digite el codigo profesorUD"<<endl;
			 cin>> Prof.Codigo;
			 cout<<"Digite el nombre "<<endl;
			 cin>> Prof.Nombre;
			 cout<<"Digite el apellido "<<endl;
			 cin>> Prof.Apellido;
			 cout<<"Digite la materia "<<endl;
			 cin>> Prof.Materia;
			 
			 do{
			 	cout<<"Digite la contrasena"<<endl;
	 	     	cin>>log.password;
	 	     	cout<<"confirme la contrasena"<<endl;
	 	     	cin>>log.confirPass;
	 	     	repet = strcmp(log.password,log.confirPass);
	 	     	if(repet == 0){
	 	     		cout<<"La contraseña coinciden, click para continuar"<<endl;
	 	     		getch();
			  	}else{
			  		cout<<"La contrasena no coinciden, vuelva a ingresar la contrasena"<<endl;
			  	}	 	     
	 	 	}while(repet != 0);
	 	     
			 Maestro<<Prof.Codigo<<" "<<Prof.Nombre<<" "<<Prof.Apellido<<" "<<Prof.Materia<<endl;
			 dateBaseLog << log.user <<" "<<  Prof.Codigo << " "<< log.password << " " << log.confirPass << " " << "Profe" <<endl;
	 	   	 cout<<"El usuario fue registrado exitosamente "<<endl<<endl;
			 
	 }
	 Maestro.close();
	 dateBaseLog.close();  
}

void cambioContraProfe(char codigo[30]){
	dateBaseLog.close();
		int b=1;
		int repet=1;
		
		ifstream dateBaseLog;
		dateBaseLog.open("BaseDatosLogginUD.txt", ios::in);
		
	  	ofstream modiDBL;
		modiDBL.open("ModBaseDatosUD.txt", ios::out);
		
	if(dateBaseLog.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   	}else{
			   
			   dateBaseLog>>log.user;
			   while(!dateBaseLog.eof()){
			   dateBaseLog>>log.cod>>log.password>>log.confirPass>>log.ident;
				b = strcmp(log.cod,codigo);
					
				if(b == 0){	
			    cout<<"Digite el numero de identificacion/cedula del Profesor"<<endl;
	 	   		cin>>log.user;
	 	   		do{
			 			cout<<"Digite la contrasena"<<endl;
	 	     			cin>>log.password;
	 	     			cout<<"confirme la contrasena"<<endl;
	 	     			cin>>log.confirPass;
	 	     			repet = strcmp(log.password,log.confirPass);
	 	     			
	 	     			if(repet == 0){
	 	     				cout<<"La contraseña coinciden, click para continuar"<<endl;
	 	     				getch();
			  			}else{
			  				cout<<"La contrasena no coinciden, vuelva a ingresar la contrasena"<<endl;
			  			}	 	  
						     
	 	 		}while(repet != 0);
	 	   		     modiDBL << log.user <<" "<< codigo << " "<< log.password << " " << log.confirPass << " " << log.ident <<endl;
	 	   		b=1;
	 	   		}else{
	 	   		     modiDBL << log.user <<" "<< log.cod << " "<< log.password << " " << log.confirPass << " " << log.ident <<endl;
	 	   		}
	 	   		dateBaseLog>>log.user;
			}
			
			dateBaseLog.close();
			modiDBL.close();
			 
    		remove("BaseDatosLogginUD.txt");
    		rename("ModBaseDatosUD.txt","BaseDatosLogginUD.txt");
	 }
}

void modificarProfe(){
	dateBaseLog.close();
		system("cls");
		int a=1;
		char codigo[30];
			 
		ifstream Maestro;
		Maestro.open("ProfesoresUD.txt", ios::in);
		
		ofstream modifProfe;
		modifProfe.open("ModProfesoresUD.txt", ios::out);
		
	    cout<<"Digite el codigo del profesor que desea modificar "<<endl;
		cin>>codigo;
			 
	    
		if(Maestro.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   		}else{			 
			 
			 Maestro>>Prof.Codigo;
			 
			 while(!Maestro.eof()){
						
	 			Maestro>>Prof.Nombre>>Prof.Apellido>>Prof.Materia;
				a = strcmp(codigo,Prof.Codigo);
			if(a == 0){
			 			cout<<"Digite los nuevos datos del profesor "<<Prof.Codigo<<endl;
				        cout<<"Digite el nombre "<<endl;
						cin>> Prof.Nombre;
						cout<<"Digite el apellido "<<endl;
						cin>> Prof.Apellido;
						cout<<"Digite la materia "<<endl;
						cin>> Prof.Materia;
			 			modifProfe<<codigo<<" "<<Prof.Nombre<<" "<<Prof.Apellido<<" "<<Prof.Materia<<endl;
						a=1;
			}else{
				modifProfe<<Prof.Codigo<<" "<<Prof.Nombre<<" "<<Prof.Apellido<<" "<<Prof.Materia<<endl;
			}	
				Maestro >> Prof.Codigo;
	 	   	}
	 	   	
	 	   	Maestro.close();
			modifProfe.close();
    		cambioContraProfe(codigo);
			remove("ProfesoresUD.txt");
    		rename("ModProfesoresUD.txt","ProfesoresUD.txt");
	}
		 	  		 
}

void elimnContraProfe(char codigo[30]){
	dateBaseLog.close();
		int b=1;
		int repet=1;
		
		ifstream dateBaseLog;
		dateBaseLog.open("BaseDatosLogginUD.txt", ios::in);
		
	  	ofstream modiDBL;
		modiDBL.open("ModBaseDatosUD.txt", ios::out);
		
	if(dateBaseLog.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   	}else{
			   
			   dateBaseLog>>log.user;
			   while(!dateBaseLog.eof()){
			   dateBaseLog>>log.cod>>log.password>>log.confirPass>>log.ident;
				b = strcmp(log.cod,codigo);
					
				if(b == 0){	
	 	   		do{
	 	   				cout<<"Digite la contraseña para borrar la informacion"<<endl;
			 			cout<<"Digite la contrasena"<<endl;
	 	     			cin>>log.password;
	 	     			cout<<"confirme la contrasena"<<endl;
	 	     			cin>>log.confirPass;
	 	     			repet = strcmp(log.password,log.confirPass);
	 	     			
	 	     			if(repet == 0){
	 	     				cout<<"La contraseña coinciden, click para continuar"<<endl;
	 	     				getch();
			  			}else{
			  				cout<<"La contrasena no coinciden, vuelva a ingresar la contrasena"<<endl;
			  			}	 	  
						     
	 	 		}while(repet != 0);
					 cout<<"La base de datos fue actualizada, se ha borrado la informacion "<<endl;
	 	   			 b=1;
	 	   		}else{
	 	   		     modiDBL << log.user <<" "<< log.cod << " "<< log.password << " " << log.confirPass << " " << log.ident <<endl;
	 	   		}
	 	   		dateBaseLog>>log.user;
			}
			
			dateBaseLog.close();
			modiDBL.close();
			 
    		remove("BaseDatosLogginUD.txt");
    		rename("ModBaseDatosUD.txt","BaseDatosLogginUD.txt");
	 }
}

void eliminProfe(){
		int a=0;
		int i=0;
		char codigo[15];
		system("cls");
		ifstream Maestro;
		Maestro.open("ProfesoresUD.txt", ios::in);
		
		ofstream elimProfe;
		elimProfe.open("ElimProfesorUD.txt", ios::out);
		
		
		cout<<"Digite el codigo del profesor que desea eliminar "<<endl;
		cin>>codigo;
			 
		if(Maestro.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   }else{
			 Maestro>>Prof.Codigo;
			 
					while(!Maestro.eof()){
					Maestro>>Prof.Nombre>>Prof.Apellido>>Prof.Materia;				 
					a = strcmp(codigo,Prof.Codigo);
					if(a == 0){
			 			i++;
			 		}else{
						
						elimProfe<<Prof.Codigo<<" "<<Prof.Nombre<<" "<<Prof.Apellido<<" "<<Prof.Materia<<endl;
			 		}		 		
					Maestro>>Prof.Codigo;
			 }
			 if(i == 0){
 	  		 	  cout<<"No se encontro los datos "<<endl;
			 }else{
			 	   elimnContraProfe(codigo);
             }
			 Maestro.close();
			 elimProfe.close();
			 
			 remove("ProfesoresUD.txt");
       		 rename("ElimProfesorUD.txt","ProfesoresUD.txt");     	
	 }
}
// ----------------------------Fin Menu Administrador - Profesores -------------------------


// ----------------------------Inicio Menu Administrador - Materias -------------------------
void crearMateria(){
		system("cls");
		Asignatura.open("MateriasUD.txt", ios::out | ios::app);
		
		if(Asignatura.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   }else{
			 int mas=0;
			 
			 do{
			 cout<<"Digite el codigo "<<endl;
			 cin>> Mater.Codigo;
			 cout<<"Digite el nombre "<<endl;
			 cin>> Mater.Nombre;
			 Asignatura<<Mater.Codigo<<" "<<Mater.Nombre<<endl;
			 
			 cout<<"Desea digitar una nueva Materia? si(1)/no(2)";
			 cin>>mas;
			}while(mas != 2);
	 }
	 Asignatura.close();
}

void modificarMateria(){
		system("cls");
		ifstream Asignatura;
		Asignatura.open("MateriasUD.txt", ios::in);
		
		ofstream modifMate;
		modifMate.open("ModMateriasUD.txt", ios::out);
		
		
		if(Asignatura.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   }else{
			 int cant=0;
			 int a=0;
			 char codigo[15];
			 
			 
			 cout<<"Digite el codigo de la materia que desea modificar "<<endl;
			 cin>>codigo;
			 
			 Asignatura>>Mater.Codigo;
			 
					while(!Asignatura.eof()){
					Asignatura>>Mater.Nombre;		 
					a = strcmp(codigo,Mater.Codigo);
					if(a == 0){
			 			cout<<"Digite los nuevos datos de la Materia "<<Mater.Codigo<<endl;
			 			cout<<"Digite el codigo "<<endl;
                        cin>> Mater.Codigo;
				        cout<<"Digite el nombre "<<endl;
						cin>> Mater.Nombre;
			 			modifMate<<Mater.Codigo<<" "<<Mater.Nombre<<endl;
			 			cout<<"Los datos han sido modificados "<<endl;			 
					}else{
						modifMate<<Mater.Codigo<<" "<<Mater.Nombre<<endl;
			 		}		 		
					Asignatura>>Mater.Codigo;
			 }
			 Asignatura.close();
			 modifMate.close();
			 
			 remove("MateriasUD.txt");
       		 rename("ModMateriasUD.txt","MateriasUD.txt");
	 }
}

void eliminMateria(){
		system("cls");
		ifstream Asignatura;
		Asignatura.open("MateriasUD.txt", ios::in);
		
		ofstream elimMate;
		elimMate.open("ElimMateriasUD.txt", ios::out);
		
		
		if(Asignatura.fail()){
	 			
			 printf("Error, no existe el archivo");   
			 
   }else{
			 int a=0;
			 int i=0;
			 char codigo[15];
			 
			 
			 cout<<"Digite el codigo de la materia que desea eliminar "<<endl;
			 cin>>codigo;
			 
			 Asignatura>>Mater.Codigo;
			 
			while(!Asignatura.eof()){
				Asignatura>>Mater.Nombre;				 
				a = strcmp(codigo,Mater.Codigo);
				if(a == 0){
		 			cout<<"Los datos de la materia "<<Mater.Codigo<<" fueron eliminados "<<endl;
					i++;
		 		}else{
					elimMate<<Mater.Codigo<<" "<<Mater.Nombre<<endl;
		 		}		 		
				Asignatura>>Mater.Codigo;
			 }
			 
			 if(i == 0){
 	  		 	  cout<<"No se encontro la materia "<<endl;
			 }else{
			 	   cout<<"La base de datos se ha actualizado"<<endl;
             }
			 
			 Asignatura.close();
			 elimMate.close();
			 
			 remove("MateriasUD.txt");
       		 rename("ElimMateriasUD.txt","MateriasUD.txt");     	
	 }
}
// ----------------------------Fin Menu Administrador - Materias -------------------------
// ----------------------------Fin Opciones Administrador -------------------------


//-------------------------------------Inicio Opciones Profesor----------------------------------



void capturaNotas(char usuario[30]){
	 system("cls");
	 int a=1;
	 int b=1;
	 int d=1;
	 int f=1;
	 int e=0;
	 int cantNotas;
	 float Notas[50];
	 float c=0;
	 
	 capturaNota.open("CapturarNotasUD.txt", ios::out | ios::app);
	 fstream Aprendiz;
	 Aprendiz.open("EstudiantesUD.txt", ios::in);
	 fstream Maestro;
	 Maestro.open("ProfesoresUD.txt", ios::in);
	 fstream Asignatura;
	 Asignatura.open("MateriasUD.txt", ios::in);
	 
	 if(capturaNota.fail() || Aprendiz.fail() || Maestro.fail()){
		printf("Error, no existe el archivo");  
		 
	 }else{
  	 	   
  	 	   cout<<"Digite la materia"<<endl;
  	 	   cin>>capNotas.elegMater;
  	 	   cout<<"Digite el codigo de estudiante"<<endl;
  	 	   cin>>capNotas.codEstud;
  	 	   cout<<"Digite la cantidad de notas del estudiante"<<endl;
  	 	   cin>>capNotas.notasN;
  	 	   
	  	   Aprendiz >> Estud.Nombre;
	  	   Maestro >> Prof.Codigo;
	  	   Asignatura >> Mater.Codigo;
 	   
		  while(!Aprendiz.eof() && !Maestro.eof()){
			  
			  if((a >= 1 || a <=-1)&&(f >= 1 || f <=-1)){
			  Maestro>>Prof.Nombre>>Prof.Apellido>>Prof.Materia;
			  a=strcmp(capNotas.elegMater,Prof.Materia);
			  f=strcmp(Prof.Codigo, usuario);
			  }
			  if(b >= 1 || b <=-1){
			  Aprendiz>>Estud.Apellido>>Estud.Sexo>>Estud.Ident>>Estud.CodEst>>Estud.Carrera>>Estud.Semestre;		 
			  b=strcmp(capNotas.codEstud,Estud.CodEst);
			  
			  }
			  
			  if(d >= 1 || d <=-1){
			  	Asignatura >> Mater.Nombre;
			  	d = strcmp(Mater.Nombre, capNotas.elegMater);
			  }
			  
			  
			  if( a == 0 && b == 0 && d == 0 && f == 0){
				   for(int i=0; i<capNotas.notasN; i++){
		   		   cout<<"Digite la nota numero "<<i+1<<endl;
		   		   cin>>Notas[i];
		   		   c += Notas[i]; 
		   		   
		   		   if(i == (capNotas.notasN-1)){
			   		   capNotas.promed = (c/capNotas.notasN);
			   		   cout<<"prom"<<capNotas.promed;
				   }
				   				   
				   capNotas.notaCant =  Notas[i];
				   
		   		   capturaNota<<Prof.Materia<<" "<<Estud.CodEst<<" "<<i+1<<" "<<capNotas.notaCant<<" "<<capNotas.promed<<endl;
		   		  // cout<<Prof.Materia<<" "<<Estud.CodEst<<" "<<i+1<<" "<<capNotas.notaCant<<" "<<capNotas.promed<<endl;
		   		   
			 	   }
			 	   capNotas.promed = (capNotas.promed/capNotas.notasN);
			 	   
			  a = 1;
 	   		  b = 1;   
			  d = 1; 
			  f = 1;   
 	   		  e = 1;
 	   		  }
			  Aprendiz >>Estud.Nombre; 
			  Maestro>>Prof.Codigo;
	  	   	  Asignatura >> Mater.Codigo;
          }
  	 }
  	 
  	 capturaNota.close();
  	 Aprendiz.close();
  	 Maestro.close();
  	 
  	 if(e == 0){
  	 	cout<<"Los Datos son incorrectos, por favor vuelvalo a intentar "<<endl;
  	 	getch();
  	 	capturaNotas(usuario);
	 }
}

void modificarNota(char usuario[30]){
	 system("cls");
	 int a=1;
	 int b=1;
	 int d=1;
	 int e=0;
	 int f=1;
	 int i=0;
	 float c=0;
	 float Notas[50];
	 char modMater[50];
	 char codEstMater[50];
	 float notaNMater;
	 
	 
	 fstream capturaNota;
	 capturaNota.open("CapturarNotasUD.txt", ios::in);
	 ofstream modifNote;
	 modifNote.open("ModificarNotaUD.txt", ios::out);
	 fstream Maestro;
	 Maestro.open("ProfesoresUD.txt", ios::in);
	 
	 if(capturaNota.fail()){
		printf("Error, no existe el archivo");  
		 
	 }else{
  	 	   
  	 	   cout<<"Digite la materia"<<endl;
  	 	   cin>>modMater;
  	 	   cout<<"Digite el codigo de estudiante"<<endl;
  	 	   cin>>codEstMater;
  	 	   cout<<"Digite el numero de nota que quiere editar"<<endl;
  	 	   cin>>notaNMater;
  	 	   
		   capturaNota>>capNotas.elegMater;
 	   	   Maestro >> Prof.Codigo;
 	   	   
		  while(!capturaNota.eof()){
			  capturaNota>>capNotas.codEstud>>capNotas.notasN>>capNotas.notaCant>>capNotas.promed;
 	   	   	  
			  
			  if(f >= 1 || f <=-1){
			  	Maestro>>Prof.Nombre>>Prof.Apellido>>Prof.Materia;
			  	f=strcmp(Prof.Codigo, usuario);
			  }
			
				a=strcmp(capNotas.elegMater,modMater);
			    b=strcmp(capNotas.codEstud,codEstMater);
			  
			  if(capNotas.notasN == notaNMater){
				 d=0;
			  }else{
			  	 d=1;	
	  		  }
	  		  
	  		  cout<<"capNotas.notasN "<<capNotas.notasN<<endl;
			  cout<<"notaNMater "<<notaNMater<<endl;
			  
			  	   
			   cout<<"a "<<a<<endl;
			   cout<<"b "<<b<<endl;
			   cout<<"d "<<d<<endl;
			   cout<<"f "<<f<<endl;
			  if( a == 0 && b == 0 && d == 0 && f == 0){
				   cout<<"Digite la nota numero "<<notaNMater<<" que quiere cambiar"<<endl;
		   		   cin>>capNotas.notaCant;
		   		  
		   		   modifNote<<capNotas.elegMater<<" "<<capNotas.codEstud<<" "<<capNotas.notasN<<" "<<capNotas.notaCant<<" "<<capNotas.promed<<endl;
			 	   e = 1;
			 	   f = 1;
			 	   cout<<"La nota fue modificada"<<endl;
			 	   getch();
 	   		  }else{
			  		
			  		modifNote<<capNotas.elegMater<<" "<<capNotas.codEstud<<" "<<capNotas.notasN<<" "<<capNotas.notaCant<<" "<<capNotas.promed<<endl;
			  } 
 	   		  capturaNota>>capNotas.elegMater;
 	   		   
			 if(f >= 1 || f <=-1){
			  	Maestro >> Prof.Codigo;
			 }
			 i=0;
			 c=0;
          }
          
          if( e == 0){
		  		cout<<"Los datos son incorrectos!!!, vuelva a intentarlo"<<endl;
		  		getch();
		  		modificarNota(usuario);
		  }
  	 }
  	 
  	 capturaNota.close();
  	 modifNote.close();
  	 Maestro.close();
  	 remove("CapturarNotasUD.txt");
	 rename("ModificarNotaUD.txt","CapturarNotasUD.txt");
}

void eliminarNota(char usuario[30]){
	 system("cls");
	 int a=1;
	 int b=1;
	 int d=1;
	 int e=0;
	 int f=1;
	 int i=0;
	 float c=0;
	 char elimMater[50];
	 char codEstMater[50];
	 float notaNMater;
	 
	 
	 fstream capturaNota;
	 capturaNota.open("CapturarNotasUD.txt", ios::in);
	 ofstream eliminNote;
	 eliminNote.open("EliminarNotaUD.txt", ios::out);
	 fstream Maestro;
	 Maestro.open("ProfesoresUD.txt", ios::in);
	 
	 if(capturaNota.fail()){
		printf("Error, no existe el archivo");  
		 
	 }else{
  	 	   
  	 	   cout<<"Digite la materia"<<endl;
  	 	   cin>>elimMater;
  	 	   cout<<"Digite el codigo de estudiante"<<endl;
  	 	   cin>>codEstMater;
  	 	   cout<<"Digite el numero de nota que quiere editar"<<endl;
  	 	   cin>>notaNMater;
  	 	   
		   capturaNota>>capNotas.elegMater;
 	   	   Maestro >> Prof.Codigo;
 	   	   
		  while(!capturaNota.eof()){
			  capturaNota>>capNotas.codEstud>>capNotas.notasN>>capNotas.notaCant>>capNotas.promed;
 	   	   	  
			  a=strcmp(capNotas.elegMater,elimMater);
			  b=strcmp(capNotas.codEstud,codEstMater);
			  
			  if(f >= 1 || f <=-1){
			  	Maestro>>Prof.Nombre>>Prof.Apellido>>Prof.Materia;
			  	f=strcmp(Prof.Codigo, usuario);
			  }
			  
			  if(capNotas.notasN == notaNMater){
				 d=0;
			  }else{
			  	 d=1;	
	  		  }
			  
			  if( a == 0 && b == 0 && d == 0 && f == 0){
				
		   		   capNotas.notaCant = 0;
		   		   i++;
		   		   c += capNotas.notaCant; 
				   			 
			   	    if(i == capNotas.notasN){					   		
				   		//capNotas.promed = (c/capNotas.notasN);
					}
				   
		   		   eliminNote<<capNotas.elegMater<<" "<<capNotas.codEstud<<" "<<capNotas.notasN<<" "<<capNotas.notaCant<<" "<<capNotas.promed<<endl;
			 	   e = 1;
			 	   f = 1;
			 	   cout<<"La nota fue eliminada"<<endl;
 	   		  }else{
			  		i++;
		   		    c += capNotas.notaCant; 
				   	if(i == capNotas.notasN){					   		
				   		  // capNotas.promed = (c/capNotas.notasN);
					}
					   
			  		eliminNote<<capNotas.elegMater<<" "<<capNotas.codEstud<<" "<<capNotas.notasN<<" "<<capNotas.notaCant<<" "<<capNotas.promed<<endl;
			  } 
			  if(f >= 1 || f <=-1){
			 	 Maestro >> Prof.Codigo;
			  }
 	   		  capturaNota>>capNotas.elegMater;
          }
          
          if( e == 0){
		  		cout<<"Los datos son incorrectos!!!, vuelva a intentarlo"<<endl;
		  		getch();
		  		eliminarNota(usuario);
		  }
  	 }
  	 
  	 capturaNota.close();
  	 eliminNote.close();
  	 Maestro.close();
  	 remove("CapturarNotasUD.txt");
	 rename("EliminarNotaUD.txt","CapturarNotasUD.txt");
}
//-------------------------------------Fin Opciones Profesores----------------------------------


//-------------------------------------Inicio Opciones Estudiantes----------------------------------
void verNotas(char usuario[30]){
	 system("cls");
 	 int a=1;
  	 int b=1;
	 int c=1;
	 int e=0;
	 int i=0;
	 int x=0;
	
	 fstream capturaNota;	
	 capturaNota.open("CapturarNotasUD.txt", ios::in);
	 fstream Aprendiz;
	 Aprendiz.open("EstudiantesUD.txt", ios::in);
	 fstream dateBaseLog;
     dateBaseLog.open("BaseDatosLogginUD.txt", ios::in);
	 
	 
	 if(capturaNota.fail() || Aprendiz.fail() || Maestro.fail()){
		printf("Error, no existe el archivo");  
	 }else{
	 
	 	capturaNota>>capNotas.elegMater;
	 	Aprendiz >> Estud.Nombre;
 	   	dateBaseLog >> log.user;
	 	   
		while(!capturaNota.eof() || !Aprendiz.eof() || !dateBaseLog.eof()){
			
			if(a >= 1 || a <=-1){
				capturaNota>>capNotas.codEstud>>capNotas.notasN>>capNotas.notaCant>>capNotas.promed;
				a = strcmp(capNotas.codEstud,usuario);
			}
			
			if(b >= 1 || b <=-1){
				Aprendiz>>Estud.Apellido>>Estud.Sexo>>Estud.Ident>>Estud.CodEst>>Estud.Carrera>>Estud.Semestre;					
				b = strcmp(Estud.CodEst,usuario);
			}
			
				 
			if(c >= 1 || c <=-1 ){
				dateBaseLog>> log.cod>>log.password>>log.confirPass>>log.ident;	
					c = strcmp(log.cod, usuario);
					
			}  
		   
			if(a == 0 && b == 0 && c == 0 ){
			
				    while(!capturaNota.eof()){
					
					if(strcmp(capNotas.codEstud,usuario) == 0){
					
					if(x==0){
						cout<<"|             Nombre            |        Materia       |"<<endl;
						cout<<"          "<<Estud.Nombre<<" "<<Estud.Apellido<<"              "<<capNotas.elegMater<<endl;
						x=1;
					}
					
					i++;
					cout<<"Nota "<<i<<" = "<<capNotas.notaCant<<endl;
					
					if(i == capNotas.notasN && capNotas.promed != 0){
						cout<<"Promedio " << capNotas.promed << endl;
						x=0;
						a=1;
						b=1;
						c=1;
						i=0;
						e=1;						
					}
				}
					capturaNota>>capNotas.elegMater>>capNotas.codEstud>>capNotas.notasN>>capNotas.notaCant>>capNotas.promed;
				} 			
					 
			    x=0;
				i=0;				
			}
			if(a >= 1 || a <=-1){
			capturaNota >> capNotas.elegMater;
			}
			if(b >= 1 || b <=-1){
	 		Aprendiz >> Estud.Nombre;
	 		}
	 		if(c >= 1 || c <=-1 ){
 	   		dateBaseLog >> log.user;
 	   		}
		}
 	   	 
	 	capturaNota.close();
	 	Aprendiz.close();
 	   	dateBaseLog.close();
	 }
	 if(e == 1){
	 	getch();
		salir();
		} 
	 
}
//-------------------------------------Fin Opciones Estudiantes----------------------------------


//-------------------------------------Inicio Administrador----------------------------------
void Administrador(){
		system("cls");
		int opcP;
		int opcS;
		int i=0;
		
		opcP = menuPrimario(opcP);
		opcS = menuSecundario(opcS);
		
		
		switch(opcP){

				case 1: 
				system("cls");
				cout<<"1- Estudiantes  " <<endl;
				if(opcS == 1){
					cout<<"1- Crear Estudiante " <<endl;
					crearEstudiante();
				}else if(opcS == 2){
					cout<<"2- Modificar Estudiante  "<<endl;
					modificarEstud();
				}else if(opcS == 3){
					cout<<"3- Eliminar Estudiante"<<endl;
					eliminEstud();
				}													

				break;
				
				case 2: 
				system("cls");
				cout<<"2- Profesores   "<<endl;
				if(opcS == 1){
					cout<<"1- Crear Profesor " <<endl;
					crearProfe();
				}else if(opcS == 2){
					cout<<"2- Modificar Profesor "<<endl;
					modificarProfe();
				}else if(opcS == 3){
					cout<<"3- Eliminar Profesor "<<endl;
					eliminProfe();
				}	
				break;
				
				case 3:
				system("cls");
				cout<<"3- Materias "<<endl;
				if(opcS == 1){
					cout<<"1- Crear Materia " <<endl;
					crearMateria();
				}else if(opcS == 2){
					cout<<"2- Modificar Materia"<<endl;
					modificarMateria();
				}else if(opcS == 3){
					cout<<"3- Eliminar Materia"<<endl;
				 	eliminMateria();
				}	
				break;
				
				default:
					system("cls");
					cout<<"La opcion no existe, por favor digite de nuevo "<<endl;
					Administrador();
				break;
		}

		getch();
			 
}
//-------------------------------------Fin Administrador----------------------------------


//-------------------------------------Inicio Profesor----------------------------------
void Profesor(char usuario[30]){
	 system("cls"); 
	 int opcProf=0;
	 
	 opcProf=menuProfesor(opcProf);
	 
	 switch(opcProf){
  	 	case 1: 
	 		 	cout<<"1- Capturar Notas  " <<endl;
				capturaNotas(usuario);
				Loggin();
		break;
		
		case 2: 
			 	cout<<"2- Modificar Notas   "<<endl;
				modificarNota(usuario);
				Loggin();
		break;
	
		case 3: 
			 	cout<<"3- Eliminar Notas "<<endl;
			 	eliminarNota(usuario);
			 	Loggin();
		
		break;	
		
		case 4: 
			 	cout<<"4- Salir "<<endl;
			 	salir();
		
		break;
		
		default:
				system("cls");
				cout<<"La opcion no existe, por favor digite de nuevo "<<endl;
				getch();
				Profesor(usuario);
		break;	 
	   
     }
	   getch();
}
//-------------------------------------Fin Profesor----------------------------------


//-------------------------------------Fin Estudiantes----------------------------------
void Estudiantes(char usuario[30]){
	 system("cls");
	 int opcEst=0;
	 
	 opcEst=menuEstudiantes(opcEst);
	 
	 switch(opcEst){
  	 	case 1: 
	 		 	cout<<"1- Ver Notas  " <<endl;
	 		 	verNotas(usuario);
		break;
		
		case 2: 
			 	cout<<"3- Salir "<<endl;
				salir();
		break;	
		
		default:
				system("cls");
				cout<<"La opcion no existe, por favor digite de nuevo "<<endl;
				getch();
				Estudiantes(usuario);
		break;	 
	   
     }
	   getch();
}
//-------------------------------------Fin Estudiantes-------------------------------------------


//-------------------------------------Inicio loggin Estudiante----------------------------------
void logginEstud(){
	 system("cls");
	 int a = 1;
	 int b = 1;
	 int c = 1;
	 int d = 1;
	 int e = 0;
	 int opcLogAdm = 0;
	 char usuario[30];	 
	 char contras[30]; 
	 char confirContra [30]; 
	 
	 fstream dateBaseLog;
     dateBaseLog.open("BaseDatosLogginUD.txt", ios::in);
	 
	 if(dateBaseLog.fail()){
		   printf("Error, no existe el archivo");  
  	 }else{
	 	   cout<<"1- Estudiantes  " <<endl<<endl;
	 	   cout<<"Digite el usuario"<<endl;
	 	   cin>>usuario;
	 	   cout<<"Digite la contrasena"<<endl;
	 	   cin>>contras;
	 	   cout<<"confirme la contrasena"<<endl;
	 	   cin>>confirContra;
	 	   
	 	   
	 	   dateBaseLog >> log.user;
	 	   
	 	   while(!dateBaseLog.eof()){
	 	       
			   	dateBaseLog>> log.cod>>log.password>>log.confirPass>>log.ident;
			   	
			   		a = strcmp(log.cod , usuario);
			   		b = strcmp(log.password , contras);
			   		c = strcmp(log.confirPass , confirContra);
			   		d = strcmp(log.ident , "Estud");
	   		  
	   		   if(a == 0 && b == 0 && c == 0 && d == 0){			   		
			   		system("cls");
					Estudiantes(usuario);
			   		a = 1;
			   		b = 1;
			   		c = 1;
			   		d = 1;
			   		e = 1;
			   		
	   		   }
 		   	   dateBaseLog >> log.user;
		   }
		   if(e == 0){
		   	 	cout<<"El usuario no exite!!!, vuelvalo a intentar "<<endl;
		   	 	getch();
			   	logginEstud();
		   }
	 }
	 
	 dateBaseLog.close();
}
//-------------------------------------Fin loggin Estudiante----------------------------------


//-------------------------------------Inicio loggin Profesores----------------------------------
void logginProfe(){
	 system("cls");
	 int a = 1;
	 int b = 1;
	 int c = 1;
	 int d = 1;
	 int e = 0;
	 char usuario[30];	 
	 char contras[30]; 
	 char confirContra [30]; 
	 
	 ifstream dateBaseLog;
     dateBaseLog.open("BaseDatosLogginUD.txt", ios::in);
	 
	 if(dateBaseLog.fail()){
		   printf("Error, no existe el archivo");  
  	 }else{
  	 	
	 	   cout<<"2- Profesores   "<<endl;
	 	   cout<<"Digite el usuario"<<endl;
	 	   cin>>usuario;
	 	   cout<<"Digite la contrasena"<<endl;
	 	   cin>>contras;
	 	   cout<<"confirme la contrasena"<<endl;
	 	   cin>>confirContra;
	 	   
	 	   
	 	   dateBaseLog >> log.user;
	 	   
	 	   while(!dateBaseLog.eof()){
	 	       
			 dateBaseLog>> log.cod>>log.password>>log.confirPass>>log.ident;
			 a = strcmp(log.cod , usuario);
			 b = strcmp(log.password , contras);
			 c = strcmp(log.confirPass , confirContra);
			 d = strcmp(log.ident , "Profe");
	   		  
	   		   if(a == 0 && b == 0 && c == 0 && d == 0){			   		
			   		Profesor(usuario);
			   		a = 1;
			   		b = 1;
			   		c = 1;
			   		d = 1;
			   		e = 1;
			   		
	   		   }
 		   	   dateBaseLog >> log.user;
		   }
		   if(e == 0){
		   	 	cout<<"El usuario no exite!!!, vuelvalo a intentar "<<endl;
		   	 	getch();
			   	logginProfe();
		   }
	 }
	 
	 dateBaseLog.close();
}
//-------------------------------------Fin loggin Profesores----------------------------------


//-------------------------------------Inicio loggin Registro Administrador----------------------------------
void logginRegistAdmin(){
	 system("cls");
     dateBaseLog.open("BaseDatosLogginUD.txt", ios::out |ios::app);
     
	 if(dateBaseLog.fail()){
		   printf("Error, no existe el archivo");  
  	 }else{
	 	   
	 	   cout<<"Digite el numero de identificacion/cedula del nuevo Administrador"<<endl;
	 	   cin>>log.user;
	 	   cout<<"Digite el codigo Administrador ";
	 	   cin>>log.cod;
	 	   cout<<"Digite la contrasena"<<endl;
	 	   cin>>log.password;
	 	   cout<<"confirme la contrasena"<<endl;
	 	   cin>>log.confirPass;
	 	   
	 	   dateBaseLog << log.user <<" "<< log.cod << " "<< log.password << " " << log.confirPass << " " << "Admin" <<endl;
	 	   cout<<"El usuario fue registrado exitosamente "<<endl;
	  }
       dateBaseLog.close();       
}
//-------------------------------------Fin loggin Registro Administrador----------------------------------

//-------------------------------------Inicio loggin Administrador----------------------------------
void logginAdministrador(){
	 system("cls");
	 int a = 1;
	 int b = 1;
	 int c = 1;
	 int d = 1;
	 int e = 0;
	 int opcLogAdm = 0;
	 char usuario[30];	 
	 char contras[30]; 
	 char confirContra [30]; 
	 
	 ifstream dateBaseLog;
     dateBaseLog.open("BaseDatosLogginUD.txt", ios::in);
	 
	 if(dateBaseLog.fail()){
		   printf("Error, no existe el archivo");  
  	 }else{
	 	   cout<<"3- Administradores  "<<endl;
	 	   cout<<"Digite el usuario"<<endl;
	 	   cin>>usuario;
	 	   cout<<"Digite la contrasena"<<endl;
	 	   cin>>contras;
	 	   cout<<"confirme la contrasena"<<endl;
	 	   cin>>confirContra;
	 	   
	 	   
	 	   dateBaseLog >> log.user;
	 	   
	 	   while(!dateBaseLog.eof()){
	 	       
			dateBaseLog>> log.cod>>log.password>>log.confirPass>>log.ident;
			a = strcmp(log.cod , usuario);
			b = strcmp(log.password , contras);
			c = strcmp(log.confirPass , confirContra);
			d = strcmp(log.ident , "Admin");
		
		
	   		   if(a == 0 && b == 0 && c == 0 && d == 0){
			   		opcLogAdm = menuOpcAdministrador(opcLogAdm);
			   		
			   		if(opcLogAdm == 1){
						cout<<"1- Opciones de Administrador  " <<endl;
						dateBaseLog.close();		 
				 	  	Administrador();
				 	  	Loggin();
				 	  	
  		 	        }else if(opcLogAdm == 2){
	   		            cout<<"2- Registro de Administrador   "<<endl;
	   		            dateBaseLog.close();
	   		            logginRegistAdmin();
				 	  	Loggin();
	   		            e++;
				    }
	   			    }else if(opcLogAdm == 3){
				        cout<<"5- Salir  "<<endl;
				        salir();
	   			    }
			   		
			  		a = 1;
 	   		  		b = 1;
				    c = 1; 
	   		   }
 		   	   dateBaseLog >> log.user;
		   }
		   if(e == 0){
		   		system("cls");
		   	 	cout<<"El usuario no exite!!!, vuelvalo a intentar "<<endl;
		   	 	getch();
			   	logginAdministrador();
		   }
	 
	 
	 dateBaseLog.close();
}
//-------------------------------------Fin loggin Administrador----------------------------------


//-------------------------------------Inicio Loggin----------------------------------
void Loggin(){
	   system("cls");
	   int opcLog = 0;
	   
	   opcLog = menuLoggin(opcLog);
	   
	   switch(opcLog){
 			case 1:
				 cout<<"1- Estudiantes  " <<endl;
				 logginEstud();
				 
            break;
            
            case 2:
				 cout<<"2- Profesores   "<<endl;
				 logginProfe();
				 
            break;
            
            case 3:
				 cout<<"3- Administradores  "<<endl;
				 logginAdministrador();
            break;
            
            case 4:
				 cout<<"4- Salir  "<<endl;
				 salir();
				 
            break;
            
            default:
            	system("cls");
            	cout<<"La opcion no existe!!!, vuelva a intentarlo"<<endl;
            	getch();
				Loggin();            	
            break;
	   }
	   
	   getch();
}
//-------------------------------------Fin Loggin----------------------------------


int main(){
	   Loggin();
}
