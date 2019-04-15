import random

alcohol_density_map = {
"151 Rum":0.94, 
"Plymouth Gin":0.94,
 "Rum":0.94, 
"Tequila":0.94, 	
"Whiskey":0.94, 	
"Spiced Rum":0.96, 		
"Southern Comfort":0.97, 	
"Vodka":0.97, 	
"Tuaca":0.98, 	 	
"Green Chartreuse":1.01, 	
"Jagermeister":1.01, 	
"Grand Marnier":1.03, 	
"Brandy":1.04, 	
"Cinnamon Schnapps":1.04, 	
"Cherry Liqueur":1.04, 	
"Coconut Rum":1.04, 	
"Cointreau":1.04, 	
"Irish Mist":1.04, 	 	
"Kummel":1.04, 	 	
"Peach Liqueur":1.04, 	
"Peppermint Schnapps":1.04, 
"Sloe Gin":1.04, 
"Amarula":1.05, 	
"Baileys Irish Cream":1.05, 	
"Midori Melon Liqueur":1.05, 	
"Campari":1.06, 	
"Fruit Brandy":1.06, 	
"Limoncello":1.06, 	
"Peach Schnapps":1.06, 	
"Yellow Chartreuse":1.06, 	
"Benedictine":1.07,	
"Hpnotiq":1.07, 		
"Amaretto Di Saronno":1.08, 	
"Drambuie":1.08, 	
"Frangelico":1.08, 
"Orange Curacao":1.08, 
"Root Beer Schnapps":1.08, 	
"Apricot Liqueur":1.09, 
"Sambuca":1.09, 	
"Tia Maria":1.09, 	
"Triple Sec":1.09, 	
"Blackberry Liqueur":1.10, 	
"Blue Curacao":1.10, 	
"Maraschino Liqueur":1.10, 	
"Banana Liqueur":1.12, 
"Galliano":1.12, 	
"Green Crème de Menthe":1.12, 
"White Crème de Menthe":1.12, 
"Strawberry Liqueur":1.12, 	
"Chambord":1.13, 	
"Parfait Amour":1.13, 	
"Coffee Liqueur":1.14, 
"Dark Crème de Cacao":1.14, 
"White Crème de Cacao":1.14, 	
"Kahlua":1.16, 	
"Crème de Almond":1.16, 	
"Crème de Noyaux":1.16, 	
"Anisette":1.17, 
"Crème de Banane":1.18, 	
"Crème de Cassis":1.18, 	
"Grenadine":1.18, 	
"Butterscotch Schnapps":1.22,
"Buckfast":0.98
}


mixer_density_map = {
"Coke":1.045,
"Lemonade":1.0,
"Milk":1.034,
"Tonic":1.031,
"Irn-Bru":1.05
}

responses = {
'I can see youre a cultured individual',
'Down it fresher', 
'Hope you arent driving anytime soon', 
'You made a cracking choice'
}

def get_alcohol_weight(drink, volume):
    return volume*alcohol_density_map[drink]
 
def get_mixer_weight(drink, volume):
    return volume*mixer_density_map[drink]

def random_response():
    return responses[random.randint(0,len(responses))]
