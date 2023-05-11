# cysp2spine
cysp to spine converter for solely Priconne.
Right now, I have only tested it on pPeco and it works. This isn't the silver bullet to whatever solution you are seeking but I hope it helps.

To use this program, first put all the cysp files into a folder with the unit-id amd then run it as main.exe {folder name}
The .exe will look for these nine files: 
{unit id}_CHARA_BASE.cysp
{unit id}_COMMON_BATTLE.cysp
{unit id}_BATTLE.cysp
{unit id}_RUN_JUMP.cysp
{unit id}_NO_WEAPON.cysp
{unit id}_SMILE.cysp
{unit id}_RACE.cysp
{unit id}_DEAR.cysp
{unit id}_POSING.cysp

DO NOT OPEN THESE FILES IN NOTEPAD, ONLY USE HxD TO MODIFY THEM BECAUSE ALL THE 0x00 BYTES WILL TRANFORM INTO 0x20
