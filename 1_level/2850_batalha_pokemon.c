#include <stdio.h>

struct pokemon {
    char nome[51];
    int id;
    int life;
    int dano;
};

void set_struct (int i, int n, struct pokemon pokemons[])
{
    if (i < n)
    {
        scanf("%s %d %d %d", pokemons[i].nome, &pokemons[i].id, &pokemons[i].dano, &pokemons[i].life);
        set_struct(i + 1, n, pokemons);
    }
}

void print_struct (int i, int n, struct pokemon treinador[])
{
    if (i < n)
    {
        printf("%s %d %d %d\n", treinador[i].nome, (treinador[i]).id, treinador[i].dano, treinador[i].life);
        print_struct(i + 1, n, treinador);
    }
}

int id_pokemon_mais_forte (int i, int n, struct pokemon pokemons[], int index)
{
    if (i < n)
    {
        if (pokemons[i].dano > pokemons[index].dano)
        {
            index = i;
        }
        else if (pokemons[i].dano == pokemons[index].dano)
        {
            if (pokemons[i].id < pokemons[index].id)
            {
                index = i;       
            }
        }
        
        return id_pokemon_mais_forte(i + 1, n, pokemons, index);
    }
    
    return index;
}

void batalha (struct pokemon *red, struct pokemon *blue)
{
     if ((*red).life > 0 && (*blue).life > 0)
     {
         (*red).life -= (*blue).dano;
         (*blue).life -= (*red).dano;
         
         batalha(red, blue);
     }
}

int main ()
{
    struct pokemon red[6];
    struct pokemon blue[6];
    
    set_struct(0, 6, red);
    set_struct(0, 6, blue);
    
    int id_red  = id_pokemon_mais_forte(1, 6, red, 0);
    int id_blue = id_pokemon_mais_forte(1, 6, blue, 0);
    
    batalha(&red[id_red], &blue[id_blue]);
    
    printf("Pokemon do Red: %s\n", red[id_red].nome);
    printf("Pokemon do Blue: %s\n", blue[id_blue].nome);
    
    if (blue[id_blue].life <= 0 && red[id_red].life <= 0)
    {
        printf("Empate\n");
    }
    else if (blue[id_blue].life > red[id_red].life)
    {
        printf("Vencedor: Blue\n");
    }
    else
    {
        printf("Vencedor: Red\n");
    }
    
    return 0;

}
