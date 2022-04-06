#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){
	
	int cont111=0,cont222=0,cont333=0,cont444=0,cont11=0,cont22=0,cont44=0,menu;
	aqui:
		
    setlocale(LC_ALL,"Portuguese");
	
	printf("Escolha uma opção: \n");
	printf("1 | Votar           \n");
	printf("2 | Apuração de votos\n");		
	printf("3 | Sair \n");		
	fflush(stdin);
	scanf("%d", &menu);	
	
	while(menu==3){
		
		printf("Encerrando a sessão... \n");
		system("pause");
		system("CLS");
		goto fim;
	}
	while (menu==1){
		system("CLS");
		printf(" Escolha um Vereador(a):\n");
		printf("  111 | João do Frete \n");
		printf("  222 | Maria da Pamonha \n");		
		printf("  333 | Zé da Farmácia \n");		
		printf("  444 | Nulo \n");		
		fflush(stdin);
	    scanf("%d", &menu);
		system("CLS");	
		switch (menu){
			case 111: 	           
			    printf("voto computado\n");
	            system ("pause");
			    system("CLS");
				cont111=cont111+1;
				break;
			case 222:
				printf("voto computado! \n");
	            system ("pause");
			    system("CLS");
				cont222=cont222+1;
				break;
			case 333:
			    printf("voto computado! \n");
	            system ("pause");
			    system("CLS");
				cont333=cont333+1;
				break;
			case 444:
				printf("voto computado! \n");
	            system ("pause");
			    system("CLS");
				cont444=cont444+1;
				break;
			default: 
			    printf ("Opção inválida!!!\n");
			    system ("pause");	
				break;
		}		
		system("CLS");
		printf("    Escolha um Prefeito:   \n");
		printf("  11 | Dr. Zureta          \n");
		printf("  22 | Senhor Gomes        \n");		
		printf("  44 | Nulo                \n");		
		fflush(stdin);
	    scanf("%d", &menu);
		system("CLS");	
		switch (menu){
			case 11: 
	            printf("voto computado! \n");
	            system ("pause");
			    system("CLS");
				cont11=cont11+1;
				break;
			case 22:
	            printf("voto computado! \n");
	            system ("pause");
		      	system("CLS");
				cont22=cont22+1;
				break;
			case 44:
	            printf("voto computado! \n");
	            system ("pause");
			    system("CLS");
				cont44=cont44+1;
				break;
			default: 
			    printf ("Opção inválida!!! \n ");
			    system ("pause");
			    system ("CLS");
				break;		
		}  
    	goto aqui;
	}
	while (menu==2){
		
		printf("Apuração dos votos \n");
		{
			printf("Aguarde...\n");
			
			system("CLS");
		}
		system("CLS");
		printf("|    Candidatos a Vereador      |  Votos \n");
		printf("|  111 | João do Frete           |    %d       \n",cont111);
		printf("|  222 | Maria Da Pamonha        |    %d       \n",cont222);		
		printf("|  333 | Zé da Farmácia          |    %d       \n",cont333);		
		printf("|  444 | Nulo                    |    %d       \n",cont444);	
		
		printf("\n");
		printf("\n");
		
		printf("|     Candidatos a Prefeito    |   Votos \n");		
		printf("|  11 | Dr. Zureta             |     %d      \n",cont11);
		printf("|  22 | Senhor Gomes           |     %d      \n",cont22);				
		printf("|  44 | Nulo                   |     %d      \n",cont44);		
		system("pause");
		goto aqui;	
	}

fim:
	    system("CLS");	
}
