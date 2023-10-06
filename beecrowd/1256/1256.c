#include <stdio.h>
#include <stdlib.h>

int tabela[100][100], N, M, C, aux, end;

void iniciarTabela () {
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            tabela[i][j] = -1;
}

int main() {

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
    {

        if (i != 0)
            printf("\n");
        
        iniciarTabela();

        scanf("%d", &M);

        scanf("%d", &C);

        for (int j = 0; j < C; j++)
        {
            scanf("%d", &aux);
            end = aux%M;
            
            int cont = 0;
            while (1)
            {
                if (tabela[end][cont] < 0)
                {
                    tabela[end][cont] = aux;
                    break;
                }
                cont++;
            }
            

        }

        int cont;

        // for (int i = 0; i < 100; i++)
        //     for (int j = 0; j < 100; j++)
        //         printf("%d", tabela[i][j]);
        
        for (int j = 0; j < M; j++)
        {
            cont = 0;
            printf("%d -> ", j);
            while (1)
            {
                if (tabela[j][cont] < 0)
                {
                    printf("\\\n");
                    break;
                }
                else
                {
                    printf("%d -> ", tabela[j][cont]);
                }
                cont++;
            }
            
        }
        
        
    }
    
    
    return 0;
}

