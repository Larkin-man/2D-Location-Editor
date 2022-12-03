//---------------------------------------------------------------------------
//#include <ustring.h>
//#include <System.hpp>
#include <stdio.h>
#include <Graphics.hpp>

//#include <TList>
//#include <SysUtils.hpp>
#pragma hdrstop
#include "Map.h"
//-------------------------------------------------------------------
int TMap::GetLocationIndex(const tileid ident) const
{
	for (int i = 0; i < TilesCount; ++i)
		//if (Idents[i] == ident)
		if (Idents[i][0] == ident[0]&&Idents[i][1] == ident[1]
			&&Idents[i][2] == ident[2]&&Idents[i][3] == ident[3])
			return i;
	return UndefindedId;
}
//-------------------------------------------------------------------
__fastcall TMap::TMap()
{
	FHeight = 0;
	FWidth = 0;
	Cell = NULL;
	UndefindedId = 0;
	file = NULL;
	DebugOpenTrig = false;
	Idents = NULL;
	SpritesCount = 0;
	SpriteNames = NULL;
	Buttons = NULL;
	Variants = NULL;
	//SpriteSizes = NULL;
	Sprites = NULL;
}
//-------------------------------------------------------------------
__fastcall TMap::~TMap()
{
	delete file;
	delete [] Idents;
	Destroy();
	delete SpriteNames;
	delete [] Buttons;
	delete [] Variants;
	//delete [] SpriteSizes;
	for (int i = 0; i < SpritesCount; ++i)
		delete Sprites[i];
	delete [] Sprites;
}
//-------------------------------------------------------------------
void TMap::Destroy()
{
	for (int i = 0; i < FWidth; i++)
	{
		//for (int j = 0; j < FHeight; j++)
		//	delete [] Cell[i][j].Sprites;
		delete [] Cell[i];
	}
	delete [] Cell;
}
//-------------------------------------------------------------------
void TMap::Create(int Width, int Height)
{
	//Destroy();
	Cell = new TCell*[Width];
	for(int i = 0; i < Width; i++)
		Cell[i] = new TCell[Height];
	FWidth = Width;
	FHeight = Height;
   Clear();
}
//-------------------------------------------------------------------
void TMap::Clear()
{
	int nl = GetLocationIndex(NoneTileStr);
	for(int i = 0; i < Width; i++)
		for(int j = 0; j < Height; j++)
		{
			Cell[i][j].Image = nl;
			//_wcsnset(Cell[i][j].Ident, L'_', SYMBCOUNT);
			strncpy(Cell[i][j].Ident, NoneTileStr, SYMBCOUNT);
			Cell[i][j].Radiation = 0;
			Cell[i][j].Anomally = 0;
			Cell[i][j].Triggger = 0;
			Cell[i][j].Variant = 0;
		}
}
//-------------------------------------------------------------------
bool TMap::Open(String FileName)
{
	FILE *fp = fopen(FileName.c_str(), "rb");
	if (!fp)
	{
		fclose(fp);
		throw;// (EFOpenError("Open Error"));
	}
	int W, H;
	fread(&W, sizeof(int), 1, fp);
	fread(&H, sizeof(int), 1, fp);
	if ((W>9000)||(H>9000)||(W<0)||(H<0))
	{
		fclose(fp);
		throw (ERangeError("Out of range"));
	}
	Map.Create(W, H);
	for (int i = 0; i < Map.FWidth; ++i)
		for (int j = 0; j < Map.FHeight; ++j)
		{
			fread(Map.Cell[i][j].Ident, sizeof(char), SYMBCOUNT, fp);
			  //fread(Map.Cell[i][j].Ident, sizeof(char), 3, fp);
			  //Map.Cell[i][j].Ident[1] = '\0';
			  //Map.Cell[i][j].Variant = 0;
			fread(&Map.Cell[i][j].Variant, 1, 1, fp);
			fread(&Map.Cell[i][j].Radiation, sizeof(unsigned char), 1, fp);
			fread(&Map.Cell[i][j].Anomally, sizeof(unsigned char), 1, fp);
			Map.Cell[i][j].Image = GetLocationIndex(Map.Cell[i][j].Ident);//   ConvertIdent();
			Map.Cell[i][j].ColorAnom = GetAnomallyColor(Map.Cell[i][j].Anomally);
			Map.Cell[i][j].ColorRad = GetRadiationColor(Map.Cell[i][j].Radiation);
			Map.Cell[i][j].Triggger = 0;
		}
	if (DebugOpenTrig)
	{
		tileidnl sect;
		fread(&sect, sizeof(char), 5, fp);
		int TriggersCount = 0;
		fread(&TriggersCount, sizeof(int), 1, fp);
		for (int i = 0; i < TriggersCount; ++i)
		{
			fread(&W, sizeof(int), 1, fp);
			fread(&H, sizeof(int), 1, fp);
			fread(&Map.Cell[W][H].Triggger, 1, 1, fp);
		}         //*/
		//Загрузим спрайты уважаемый сэр

		fread(&sect, sizeof(char), 5, fp);
		int sprc = 0, sprs = 0;
		fread(&sprc, sizeof(int), 1, fp);
		tileid sprt;
		for (int i = 0; i < sprc; ++i)
		{
			fread(sprt, sizeof(char), SYMBCOUNT, fp);
			fread(&sprs, sizeof(int), 1, fp);
			int x=0, y=0, sprind=-1;
			if (SpriteNames)//&&((in = Sprites->Names. IndexOf(sprt)) > -1))
			{
				for (int j = 0;j < SpriteNames->Count; ++j)
					if (strncmp(SpriteNames->Names[j].c_str(), sprt, SYMBCOUNT) == 0)
					{
						sprind = j;
						break;
					}
				if (sprind == -1)
					continue;    //*/
				for (int i = 0; i < sprs; ++i)
				{
					fread(&x, sizeof(int), 1, fp);
					fread(&y, sizeof(int), 1, fp);
					if (Sprites)
						SpritesList.push_back(TSprite(sprind,x,y));
//					if (Sprites) //
//						Cell[x/TILESIZE][y/TILESIZE].Sprites.push_back(TSprite(sprind,x%TILESIZE-Sprites[sprind]->Width,y%TILESIZE-Sprites[sprind]->Height));
//					else
//						Cell[x/TILESIZE][y/TILESIZE].Sprites.push_back(TSprite(sprind,x%TILESIZE,y%TILESIZE));
				}

			}
		}    //*/
	}
	fclose(fp);
	return true;
 }
//-------------------------------------------------------------------
bool TMap::Save(String FileName)    //Функция сохраняет список в бинарный файл
{
	FILE *fp = fopen (FileName.c_str(), "wb");
	if (!fp)
	{
		fclose(fp);
		//throw (EFOpenError("File Open Error"));
		return false;
	}
	//int ww = FWidth*2; 	int hh = FHeight; bool x2 = true;
	fwrite(&FWidth, sizeof(int), 1, fp);
	fwrite(&FHeight, sizeof(int), 1, fp);
	int TriggersCount = 0;
	for (int i = 0; i < Map.FWidth; ++i)
	{
		for (int j = 0; j < Map.FHeight; ++j)
		{
			//strncpy(Map.Cell[i][j].Ident, Map.Idents[Map.Cell[i][j].Image], SYMBCOUNT);
			if (Map.Cell[i][j].Image < UndefindedId)
				fwrite(Idents[Map.Cell[i][j].Image], sizeof(char), SYMBCOUNT, fp);
			else
				fwrite(Map.Cell[i][j].Ident, sizeof(char), SYMBCOUNT, fp);
			  //fwrite(file->Values[Map.Cell[i][j].Ident].c_str(), sizeof(char), SYMBCOUNT, fp);
			fwrite(&Map.Cell[i][j].Variant, 1, 1, fp);
			fwrite(&Map.Cell[i][j].Radiation, sizeof(unsigned char), 1, fp);
			fwrite(&Map.Cell[i][j].Anomally, sizeof(unsigned char), 1, fp);
			if (Map.Cell[i][j].Triggger > 0)
				TriggersCount++;
		}
		//if (x2) i--;		x2 = !x2;
	}
	if (DebugOpenTrig)
	{
		fwrite("TRIGS", sizeof(char), 5, fp);
		fwrite(&TriggersCount, sizeof(int), 1, fp);
		for (int i = 0; i < Map.FWidth; ++i)
			for (int j = 0; j < Map.FHeight; ++j)
				if (Map.Cell[i][j].Triggger > 0)
				{
					fwrite(&i, sizeof(int), 1, fp);
					fwrite(&j, sizeof(int), 1, fp);
					fwrite(&Map.Cell[i][j].Triggger, 1, 1, fp); //DONE:1byte
				}

		//Сохраним ка спрайты уажаемый сэр
		//TODO:peredelat cherez bazovyi vector
		std::vector<std::vector<MyPoint> >Saves(SpritesCount);
		//for (int i = 0; i < SpritesCount; ++i)
		//Saves = new std::vector<MyPoint>[SpritesCount];
		//for (int i = 0; i < Map.FWidth; ++i)
		//	for (int j = 0; j < Map.FHeight; ++j)
		for (std::vector<TSprite>::iterator el = SpritesList.begin(); el != SpritesList.end(); ++el)
			{
				//if (Map.Cell[i][j].Sprites.size() > 0)
					//for (std::vector<TSprite>::iterator el = Map.Cell[i][j].Sprites.begin(); el != Map.Cell[i][j].Sprites.end(); ++el)
			Saves[el->Index].push_back(MyPoint(el->x,el->y));
			}

		int sc = 0;
		for (std::vector<std::vector<MyPoint> >::iterator el = Saves.begin(); el != Saves.end(); ++el)
			if (el->size() > 0)
				sc++;
		fwrite("SPRTS", sizeof(char), 5, fp);
		fwrite(&sc, sizeof(int), 1, fp);
		if (sc > 0)
		for (int v = 0; v < SpritesCount; ++v)
		//for (std::vector<std::vector<MyPoint> >::iterator V = Saves.begin(); V != Saves.end(); ++V)
		{
			if (Saves[v].size() <= 0)
				continue;
			fwrite(SpriteNames->Names[v].c_str(), sizeof(char), SYMBCOUNT, fp);
			int ZAEBALA = Saves[v].size();
			fwrite(&ZAEBALA, sizeof(int), 1, fp);
			for (std::vector<MyPoint>::iterator el = Saves[v].begin(); el != Saves[v].end(); ++el)
			{
				int x = el->x+Sprites[v]->Width;
				int y = el->y+Sprites[v]->Height;
				fwrite(&x, sizeof(int), 1, fp);
				fwrite(&y, sizeof(int), 1, fp);
			} //*/
		}
		//delete [] Saves;

	}
	fclose(fp);
	return true;
}
//-------------------------------------------------------------------
TColor TMap::GetAnomallyColor(int Power)
{
	if (Power < 45)
	{
		int Light = TransformNumber(0, 255, 45, 0,Power);
		return SetRGBint(255, Light, Light);
	}
	else
	{
		int Red = TransformNumber(45, 255, 100, 64, Power);
		return SetRGBint(Red, 0, 0);
	}
}
//-------------------------------------------------------------------
TColor TMap::GetRadiationColor(int Power)
{
	if (Power < 30)
	{
		int Blue = TransformNumber(0,255,30,0,Power);
		return SetRGBint(255, 255, Blue);
	}
	else
	{
		int Green = TransformNumber(30, 255, 100, 0, Power);
		int Blue =  TransformNumber(30, 0,   100, 128, Power);
		return SetRGBint(255, Green, Blue);
	}
}
//-------------------------------------------------------------------
void TMap::TCell::SetRadiation(int iRadiation)
{
	Radiation = iRadiation;
	ColorRad = GetRadiationColor(iRadiation);
}
//-------------------------------------------------------------------
void TMap::TCell::SetAnomally(int iAnomally)
{
	Anomally = iAnomally;
	ColorAnom = GetAnomallyColor(iAnomally);
}
//-------------------------------------------------------------------
void TMap::AnomallyRun() //[W][H]
{
	int Chance;
	for (int i = 1; i < FWidth; ++i)
	{
		Chance = Cell[i][0].Anomally;
		if (Chance >= 100)
			Cell[i][0].AnomTest = true;
		else
		{
			if (Cell[i-1][0].AnomTest)
				Chance /= 2;
			if (rand()%100 < Chance)
				Cell[i][0].AnomTest = true;
			else
         	Cell[i][0].AnomTest = false;
		}
	}
	for (int i = 1; i < FHeight; ++i)
	{
		Chance = Cell[0][i].Anomally;
		if (Chance >= 100)
			Cell[0][i].AnomTest = true;
		else
		{
			if (Cell[0][i-1].AnomTest)
				Chance /= 2;
			if (rand()%100 < Chance)
				Cell[0][i].AnomTest = true;
			else
				Cell[0][i].AnomTest = false;
		}
	}
	for (int i = 1; i < FHeight; ++i)
		for (int j = 1; j < FWidth; ++j)
		{
			Chance = Cell[j][i].Anomally;
			if (Chance >= 100)
				Cell[j][i].AnomTest = true;
			else
			{
				if (Cell[j-1][i].AnomTest)
					Chance /= 2;
				if (Cell[j][i-1].AnomTest)
					Chance /= 2;
				if (Cell[j-1][i-1].AnomTest)
					Chance -= Chance/3;
				if (rand()%100 < Chance)
					Cell[j][i].AnomTest = true;
				else
					Cell[j][i].AnomTest = false;
			}
		}
}
//-------------------------------------------------------------------
void TMap::LoadTiles(const String FileName)
{
	file = new TStringList;
	try
	{
		file->LoadFromFile(FileName);
	} catch (...)
	{
		throw;
	}
	for (int i = 0; i < file->Count; ++i)
		if (unsigned(file->Strings[i].Length()) <= SYMBCOUNT)
		{
			file->Delete(i);
			i--;
		}
	TilesCount = file->Count;
	Idents = new tileidnl[TilesCount];
	tileid Group = {'0','0','0','0'};
	int nGroup = 0;
	Variants = new int[file->Count+1];
	for (int i = 0; i < TilesCount; i++)
	{
		strncpy(Idents[i], file->Names[i].c_str(), SYMBCOUNT);
		Idents[i][SYMBCOUNT] = '\0';
		//Для группировки тайлов
		if (strncmp(Group, Idents[i], SYMBCOUNT-1) == 0 && Idents[i][SYMBCOUNT-1]>='0'&&Idents[i][SYMBCOUNT-1]<='9')
		{  //одинаковы и 4-цифра
			nGroup++;
			Variants[i] = 1;
		}
		else
		{
			strncpy(Group, Idents[i], SYMBCOUNT-1);
			Variants[i] = 0;
		}

		//Idents[i][0] = file->Names[i][1];
		//Maps.Name[i] = file->Values[i+1];
	}
	Variants[file->Count] = 0;
	Buttons = new int[file->Count-nGroup];
	file->Add("Хрен знает что");
	UndefindedId = TilesCount;//GetLocationIndex(NoneTileStr);
}
//-------------------------------------------------------------------
void TMap::LoadSprites(const UnicodeString FileName)
{
	SpriteNames = new TStringList;
	SpriteNames->LoadFromFile(FileName);//"Sprites\\SPRITES.txt");
	for (int i = 0; i < SpriteNames->Count; ++i)
		if (unsigned(SpriteNames->Strings[i].Length()) <= 4)
		{
			SpriteNames->Delete(i);
			i--;
		}
	SpritesCount = SpriteNames->Count;
	Sprites = new TPicture*[SpritesCount];
	//Sprites = new TImage*[SpritesCount];
	//Idents = new tileidnl[TilesCount];
	for (int i = 0; i < SpritesCount; ++i)
	{
		Sprites[i] = new TPicture;
		Sprites[i]->Bitmap->AlphaFormat = afDefined;
		Sprites[i]->Bitmap->LoadFromFile("Sprites\\"+Map.SpriteNames->Names[i]+".bmp");// = Image3->Picture;
      //Sprites[i]->Bitmap->Transparent = true; //Это пинзевс

	}
	//SpriteSizes = new MyPoint[SpritesCount];

}
//-------------------------------------------------------------------

//-------------------------------------------------------------------
