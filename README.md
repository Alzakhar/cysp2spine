# cysp2spine
cysp to spine converter for solely Priconne.
Right now, I have only tested it on pPeco and it works. <br />

To use this program, first put all the cysp files into a folder with the unit-id amd then run it as main.exe {folder name}
The .exe will look for these nine files: <br />
{unit id}_CHARA_BASE.cysp <br />
{unit id}_COMMON_BATTLE.cysp <br />
{unit id}_BATTLE.cysp <br />
{unit id}_RUN_JUMP.cysp <br />
{unit id}_NO_WEAPON.cysp <br />
{unit id}_SMILE.cysp <br />
{unit id}_RACE.cysp <br />
{unit id}_DEAR.cysp <br />
{unit id}_POSING.cysp <br />

DO NOT OPEN THESE FILES IN NOTEPAD, ONLY USE HxD TO MODIFY THEM BECAUSE ALL THE 0x00 BYTES WILL TRANFORM INTO 0x20
