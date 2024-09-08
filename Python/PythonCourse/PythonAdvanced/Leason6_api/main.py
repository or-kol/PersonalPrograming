

import requests

base_url = "https://pokeapi.co/api/v2/"

def getPokemonInfo(name):    
    url = f"{base_url}pokemon/{name}"
    response = requests.get(url)
    if response.status_code == 200:
        return response.json()
    else:
        print(f"failed to retrieve data {response.status_code}")

    


def main():
    
    pokemon_name = "pikachu"
    poke_dict = getPokemonInfo(pokemon_name)

    if poke_dict:
        #print(f"{poke_dict['name']}")
        #print(f"{poke_dict['id']}")

        for key, val in poke_dict:
            print(f"{key}: {val}")


    



if __name__ == "__main__":
    main()