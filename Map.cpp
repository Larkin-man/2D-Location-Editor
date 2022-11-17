//---------------------------------------------------------------------------
//#include <ustring.h>
//#include <System.hpp>
#include <stdio.h>
#include <Graphics.hpp>
//#include <SysUtils.hpp>
#pragma hdrstop
#include "Map.h"
//-------------------------------------------------------------------
int TMap::GetLocationIndex(char ident)
{
	for (int i = 0; i < TilesCount; ++i)
		if (Idents[i] == ident)
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
}
//-------------------------------------------------------------------
__fastcall TMap::~TMap()
{
	delete file;
	Destroy();
}
//-------------------------------------------------------------------
void TMap::Destroy()
{
	for (int i = 0; i < FWidth; i++)
		delete [] Cell[i];
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
	int nl = GetLocationIndex('0');
	for(int i = 0; i < Width; i++)
		for(int j = 0; j < Height; j++)
		{
			Cell[i][j].Image = nl;
			Cell[i][j].Ident = '0';
			Cell[i][j].Radiation = 0;
			Cell[i][j].Anomally = 0;
			Cell[i][j].Triggger = 0;
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
			fread(&Map.Cell[i][j].Ident, sizeof(wchar_t), 1, fp);
			fread(&Map.Cell[i][j].Radiation, sizeof(unsigned char), 1, fp);
			fread(&Map.Cell[i][j].Anomally, sizeof(unsigned char), 1, fp);
			Map.Cell[i][j].Image = GetLocationIndex(Map.Cell[i][j].Ident);//   ConvertIdent();
			Map.Cell[i][j].ColorAnom = GetAnomallyColor(Map.Cell[i][j].Anomally);
			Map.Cell[i][j].ColorRad = GetRadiationColor(Map.Cell[i][j].Radiation);
			Map.Cell[i][j].Triggger = 0;
		}
	if (DebugOpenTrig)
	{
		int TriggersCount = 0;
		fread(&TriggersCount, sizeof(int), 1, fp);
		for (int i = 0; i < TriggersCount; ++i)
		{
			fread(&W, sizeof(int), 1, fp);
			fread(&H, sizeof(int), 1, fp);
			fread(&Map.Cell[W][H].Triggger, sizeof(int), 1, fp);
		}         //*/
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
			fwrite(&Map.Cell[i][j].Ident, sizeof(wchar_t), 1, fp);
			fwrite(&Map.Cell[i][j].Radiation, sizeof(unsigned char), 1, fp);
			fwrite(&Map.Cell[i][j].Anomally, sizeof(unsigned char), 1, fp);
			if (Map.Cell[i][j].Triggger > 0)
				TriggersCount++;
		}
		//if (x2) i--;		x2 = !x2;
	}
	if (DebugOpenTrig)
	{
		fwrite(&TriggersCount, sizeof(int), 1, fp);
		for (int i = 0; i < Map.FWidth; ++i)
			for (int j = 0; j < Map.FHeight; ++j)
				if (Map.Cell[i][j].Triggger > 0)
				{
					fwrite(&i, sizeof(int), 1, fp);
					fwrite(&j, sizeof(int), 1, fp);
					fwrite(&Map.Cell[i][j].Triggger, sizeof(int), 1, fp);
					//T = Map.Cell[i][j].Triggger + SSHIFT;
					//fwrite(&T, sizeof(unsigned char), 1, fp);
				}
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
		if (file->Strings[i].Length() <= 1)
		{
			file->Delete(i);
			i--;
		}
	TilesCount = file->Count;
	Idents = new wchar_t[TilesCount];
	for (int i = 0; i < TilesCount; i++)
	{
		Idents[i] = file->Names[i][1];
		//Maps.Name[i] = file->Values[i+1];
		//Memo1->Lines->Add(Maps.Ident[i]);
		//Memo1->Lines->Add(Maps.Name[i]);
		//Memo1->Lines->Add(file->Values[Maps.Ident[i]]);
	}
}
//-------------------------------------------------------------------
