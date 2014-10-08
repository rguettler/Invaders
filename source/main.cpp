#include "AIE.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

const int iScreenWidth = 672;
const int iScreenHeight = 780;  //SCREEN SIZE BITCHES
const int playerWidth = 64;
const int playerHeight = 32;

const char* bullshitMarquee = "./images/bullshitmarquee.png";
const char* invadersFont = "./fonts/invaders.fnt";
const char* windowTitle = "Space Invaders";
const char* cannonSprite = "./images/cannon.png";
const char* scorePlayerOne = "SCORE < 1 >";
const char* highScore = "HIGH SCORE";
const char* scorePlayerTwo = "SCORE < 2 >";
const char* creditCount = "CREDIT";
const char* insertCoins = "INSERT COIN";
const char* enemyInvaders = "./images/invaders/invaders_1_00.png";

char player1Score[10] = "00000";
char playerHighScore[10] = "00000";
char player2Score[10] = "00000";
char playerCredit[10] = "99";
char playerICredits[10] = "00";


float enemyX;
float enemyY;

unsigned int invadersMarquee;
unsigned int playerCannon;

void UpdateMainMenu();
void UpdateGameState(float a_deltaTime);
void CreateEnemies();

Player player;

Enemy alienShips[24];



enum GAMESTATES
{
	main_menu,
	gameplay,
	end,

};



int main( int argc, char* argv[] )
{	
	Initialise(iScreenWidth, iScreenHeight, false, windowTitle);
	AddFont(invadersFont);
    SetBackgroundColour(SColour( 00, 00, 00, 40));
	float deltaTime = GetDeltaTime();
	
	player.SetSize(64.f, 32.f);
	player.SetMovementKeys('A', 'D');
	player.spriteID = CreateSprite(cannonSprite, player.width, player.height, true);
	player.SetPosition(iScreenWidth * 0.5f, 80.f);
	player.SetMovementExtreme(0, iScreenWidth);
	player.speed = 5000;
	
	CreateEnemies();
	
	
	
	invadersMarquee = CreateSprite(bullshitMarquee, 672, 780, false);
	

	GAMESTATES currentState = main_menu;

    //Game Loop
	do
	{
		ClearScreen();
		SetFont(invadersFont);

		switch (currentState)
		{
		case main_menu:
			UpdateMainMenu();
			if (IsKeyDown(257))
			{
				currentState = gameplay;
			}
			break;

		case gameplay:
			
			UpdateGameState(deltaTime);
			if (IsKeyDown(256))
			{
				currentState = main_menu;
			}
			
			
			break;
		default:
			break;
		}

		
    
	} while(FrameworkUpdate() == false); //FRAMES WERENT UPDATING, WATCH THIS SHIT

	DestroySprite(player.spriteID);
	DestroySprite(invadersMarquee);

	Shutdown();

    return 0;
}

void UpdateMainMenu()
{
	DrawSprite(invadersMarquee);
	MoveSprite(invadersMarquee, 0, 780);
	DrawString(insertCoins, iScreenWidth * 0.4f, iScreenHeight * 0.5f);
	DrawString(playerICredits, iScreenWidth * 0.49f, iScreenHeight *0.45f);
}

void UpdateGameState(float a_deltaTime)
	{
		for (int i = 0; i < 24; ++i)
		{
			DrawSprite(alienShips[i].spriteID);
		}

		player.Move(a_deltaTime, player.speed);


		DrawSprite(player.spriteID);
		MoveSprite(player.spriteID, iScreenWidth * 0.5f, 80.f);

		DrawLine(0, 40, iScreenWidth, 40, SColour(0x00, 0xFC, 0x00, 0xFF)); //Credit and Life Line

		DrawString(player1Score, iScreenWidth *0.06f, iScreenHeight - 25); //Player 1 Score Numeral
		DrawString(scorePlayerOne, iScreenWidth * 0.025f, iScreenHeight - 2); //Player 1 Score Title
		DrawString(highScore, iScreenWidth * 0.38f, iScreenHeight - 2); //High Score Title
		DrawString(playerHighScore, iScreenWidth * 0.425f, iScreenHeight - 25); // High Score Numeral
		DrawString(creditCount, iScreenWidth * 0.75f, iScreenHeight - 750); // Credit Counter
		DrawString(playerCredit, iScreenWidth * 0.925f, iScreenHeight - 750); //Credit Numeral
		DrawString(scorePlayerTwo, iScreenWidth * 0.75f, iScreenHeight - 2); // Player 2 Score Title
		DrawString(player2Score, iScreenWidth * 0.79f, iScreenHeight - 25); //Player 2 Score Numeral
	}

void CreateEnemies()
{
	float eX = iScreenWidth * 0.2f;
	float eY = iScreenHeight * 0.8f;
	
	for (int i = 0; i < 24; ++i)
	{
		alienShips[i].SetSize(64, 32);
		alienShips[i].spriteID = CreateSprite(enemyInvaders, alienShips[i].width, alienShips[i].height, true);
		MoveSprite(alienShips[i].spriteID, eX, eY);
		alienShips[i].x = eX;
		alienShips[i].y = eY;
		
		eX += 0.12 * iScreenWidth;
		if (eX > iScreenWidth * 0.8f)
		{
			eX = iScreenWidth * 0.2f;
			eY -= 0.08 * iScreenHeight;
		}
		
	}
}

