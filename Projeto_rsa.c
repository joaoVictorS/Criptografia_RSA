#include <stdio.h>
  #include <string.h>
  #include <math.h>
  #include <stdlib.h>


  char alfabeto[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};

  long long int inverso(long long int e, long long int fi) //calcula o inverso de 'e' com 'fi'
  {
    long long int x;
    for(x = 1; x < fi ; x++)
    {
      if((x * e) % fi == 1)
      {
        break;
      }
    }
    return x;
  }

  long long int modular(long long int m, long long int e, long long int n)
  {
    long long int c, i;
    if(n == 1)
    {
      return 0;
    }
    c = 1;
    for(i = 0; i < e; i++)
    {
      c = (c * m) % n;
    }
    return c;
  }

  long long int primo(long long int n)
  {
    long long int d, a = 0;
    if(n == 1 || n == 0)
    {
      return 0;
    }
    else
    {
      for(d = 2 ; d <= n/2 && a == 0 ; d++)
      {
        if(n % d == 0)
        {
          a = 1;
        }
      }
      if(a == 1)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
  }

  long long int mdc(long long int a, long long int b)
  {
    if(b == 0)
    {
      return a;
    }
    else
    {
      mdc(b, a % b);
    }
  }

  void chaves()
  {
    long long int fi, p, q, e;
    int w;
    FILE *keys;
    printf("Digite os valores de: p, q, e\n");
    scanf("%lld%lld%lld", &p, &q, &e);
    fi = (p - 1) * (q - 1);
    int invalido = 0;
    while(!invalido)
    {
      if(primo(p) == 0 || primo(q) == 0 || mdc(fi, e) != 1) 
      {
        printf("Valor invalido\n");
        return;
      }
      else
      {
        printf("Valor valido!\n");
        printf("Salvo em 'chaves_publicas.txt'.\n");
        keys = fopen("chaves_publicas.txt", "w");
        fprintf(keys,"%lld %lld", q * p, e);
        fclose(keys);
        printf("Para mostrar os resultados na tela digite 1\nPara sair digite 0\n");
        scanf("%d", &w);
        if(w == 1)
        {
          printf("Chaves publicas\nn=%lld\ne=%lld\n", p * q, e);
        }
        invalido = 1;
      }
    }

  }

  void cripton()
  {
    long long int n, e, tam, i, j, aux[100000], valor[100000];
    char frase[100000];
    int w;
    FILE *msg_crip;
    msg_crip = fopen("criptongirl.txt", "w");
    printf("Digite a sua chave publica 'n' e 'e':\n");
    scanf("%lld%lld", &n, &e);
    printf("Digite a mensagem a ser criptografada:\n");
    getchar();
    scanf(" %[^\n]", frase);
    tam = strlen(frase);
    for(i = 0 ; i < tam ; i++)
    {
      for(j = 0 ; j < 27 ; j++)
      {
        if(frase[i] == alfabeto[j])
        {
          aux[i] = j;
        }
      }
      valor[i] = modular(aux[i], e, n);
      fprintf(msg_crip, "%lld ", valor[i]);
    }
    printf("A mensagem foi criptografada! Salva em 'criptongirl.txt'.\n");
    printf("\n");
    printf("Deseja mostrar na tela?\nSe sim, digitar 1, caso contrario, digite 0\n");
    scanf("%d", &w);
    if(w == 1)
    {
      for(i = 0 ; i < tam ; i++)
      {
        printf("%lld ", valor[i]);
      }
      printf("\n");
    }
    fclose(msg_crip);

    w = 0;
  }

  void descripton()
  {
    long long int d, i, tam, p, q, e, fi;
    long long int mensagem[100000];
    char a[100000];
    FILE *msg_aux, *msg_desc;
    msg_aux = fopen("criptongirl.txt", "r");

    printf("Digite os valores de 'p', 'q', 'e':\n");
    scanf("%lld%lld%lld", &p, &q, &e);
    fi = (p - 1) * (q - 1);
    d = inverso(e, fi);

    for(i = 0 ; !feof(msg_aux) ; i++)
    {
      fscanf(msg_aux,"%lld ", &mensagem[i]);
    }

    tam = i;
    for(i = 0 ; i < tam ; i++)
    {
      mensagem[i] = modular(mensagem[i], d, p * q);
    }

    msg_desc = fopen("descriptongirl.txt", "w");
    for(i = 0 ; i < tam ; i++)
    {
      a[i] = alfabeto[mensagem[i]];
      fprintf(msg_desc, "%c", a[i]);
    }
    fclose(msg_desc);

    printf("Mensagem descriptografada! Salva em 'descriptongirl.txt'.\n\n");
    printf("Deseja mostrar mensagem na tela?\nDigite 1 para mostrar e 0 para sair.\n");

    int w;
    scanf("%d", &w);
    if(w == 1)
    {
      for(i = 0 ; i < tam ; i++)
      {
        printf("%c", a[i]);
      }
      printf("\n");
    }
  }

  int main()
  {

    printf(" ######   ########  ##          ########  ##      ## ########     ########   ######     ### \n");
    printf("##    ##  ##     ## ##          ##     ## ##  ##  ## ##     ##    ##     ## ##    ##   ## ## \n");  
    printf("##        ##     ## ##          ##     ## ##  ##  ## ##     ##    ##     ## ##        ##   ##  \n");
    printf("##   #### ########  ##          ########  ##  ##  ## ########     ########   ######  ##     ## \n");
    printf("##    ##  ##   ##   ##          ##        ##  ##  ## ##   ##      ##   ##         ## ######### \n");
    printf("##    ##  ##    ##  ##          ##        ##  ##  ## ##    ##     ##    ##  ##    ## ##     ## \n");
    printf(" ######   ##     ## ########    ##         ###  ###  ##     ##    ##     ##  ######  ##     ## \n");

    printf("\n");

    int escolha = 6;

    while(escolha != 4)
    {
      printf("Escolha uma opcao:\n\n1- Gerar chave publica\n2- Criptografar\n3- Descriptografar\n4- Sair\n");
      scanf("%d", &escolha);
      if(escolha == 1)
      {
        printf("GERANDO CHAVES PUBLICAS\n\n");
        chaves();
      }
      if(escolha == 2)
      {
        printf("CRIPTOGRAFANDO\n\n");   
        cripton();
      }
      if(escolha == 3)
      {
        printf("DESCRIPTOGRAFANDO\n\n");
        descripton();
      }
      if (escolha == 4)
      {
        printf("Obrigada. Volte Sempre!!!!!!!! Até próximo período!\n");
      }
    }

    return 0;
  }