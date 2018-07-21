from random import choice

Music = [
	'Michael Jackson',

	'Led Zeppelin',

	'Eagles',

	'Pink Floyd',

	'Eminem',

	'AC/DC',

	'Queen',

	'The Rolling Stones',

	'Metallica',

	'Royal Blood',

	'Rage Against the Machine',

    'System Of A Down'

]

Anime = [

	'Death Note',

	'Dragon Ball',

	'One Piece',

	'Naruto',

	'Attack on Titan',

	'Fullmetal Alchemist: Brotherhood‎',

	'Hunter x Hunter',

	'Pokemon',

	'Steins;Gate',

	'Avatar: The Last Airbender',

	'Trigun',

	'Yu-Gi-Oh!',

	'Rurouni Kenshin',

	'Elfen Lied',

	'Tengen Toppa Gurren Lagann',

	'Berserk',

	'Kill la Kill',

	'Ao no Exorcist',

	'D. Gray Man',

	'Monster',

	'Samurai Champloo',

	'Saint Seiya',

	'Parasyte The Maxim',

	'Re:ZERO',

	'Hellsing Ultimate',

	'Afro Samurai',

	'One-Punch Man'
]

Game = [

	''
	'Bravely Default'
	,
	'Gravity Rush'
	,
	'Full Throttle'
	,
	'Persona'
	,
	'Guilty gear'
	,
	'Worms Armageddon'
	,
	'Wild Arms'
	,
	'Pokémon red and blue'
	,
	'Dota 2'
	,
	'Guitar Hero'
	,
	'Mortal Kombat'
	,
	'StarCraft II'
	,
	'Final Fantasy VII'
	,
	'Grand Theft Auto'
	,
	'Counter-Strike'
	,
	'Final Fantasy VI'
	,
	'World of Warcraft'
	,
	'Minecraft'
	,
	'Doom'
	,
	'Valkyrie Profile'
	,
	'Devil May Cry 3'
	,
	'God of War'
	,
	'Rayman Legends'
	,
	'Dragon Quest VIII'
	,
	'Kingdom Hearts'
	,
	'Viewtiful Joe'
	,
	'Grim Fandango'
	,
	'Street Fighter'
	,
	'Journey'
	,
	'Abzû'
	,
	'Hollow Knight'
	,
	'Child of Light'
	,
	'Firewatch'
	,
	'The Last of Us'
	,
	'Cuphead'
	,
	'The Last Guardian'
	,
	'League of Legends'
	,
	'Transistor'
	,
	'Detection'
	,
	'Night in the Woods'
	,
	'Steamworld Dig 2'
	,
	'A Hat in Time'
]

Manga = [
	'Kamisama ga Uso wo Tsuku'
]

all = Anime + Music + Game + Manga

print('{}'.format(choice(all)))
