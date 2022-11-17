//---------------------------------------------------------------------------
//Мапер 10х10 пикселей
#ifndef MapH
#define MapH
//---------------------------------------------------------------------------

TColor SetRGBint(int Red, int Green, int Blue)//макс 255
{
	Green <<= 8;
	Blue <<= 16 ;
	return TColor(Red | Green | Blue);
}

inline int TransformNumber(int InitLeft, int FinalLeft, int InitRight, int FinalRight, int Numb)
{
	return ((FinalRight-FinalLeft)*(Numb-InitLeft))/double(InitRight-InitLeft) + FinalLeft;
}

class TMap
{
private:
	int FHeight, FWidth;

protected:
	wchar_t GetTile(int i) const	{  return Idents[i];   }
	UnicodeString GetTileName(int i) { return file->Values[Idents[i]]; }
public:
	wchar_t *Idents;
	TStringList *file;
	typedef struct
	{
		wchar_t Ident;
		unsigned char Radiation;
		unsigned char Anomally;
		int Image;
		TColor ColorRad;
		TColor ColorAnom;
		int Triggger;
		bool AnomTest;
		///void ConvertIdent()	{	Image = GetLocationIndex(Ident); }
		void SetRadiation(int iRadiation);
		void SetAnomally(int iAnomally);
	} TCell;
	void Create(int Width, int Height);    //init
	void Clear();
	__property int Width = {read=FWidth};
	__property int Height = {read=FHeight};
	TCell **Cell; //[W][H]
	bool DebugOpenTrig;
	void Destroy();
	__fastcall TMap();
	__fastcall ~TMap();
	static TColor GetAnomallyColor(int Power);
	static TColor GetRadiationColor(int Power);
	bool Open(UnicodeString FileName); //Функция загружает список из бинарного файла
	bool Save(UnicodeString FileName);
	void AnomallyRun();
	//Base Tiles
	void LoadTiles(const UnicodeString FileName);
	int TilesCount;
	__property wchar_t TileIdent[int i] = {read=GetTile};
	__property UnicodeString TileName[int i] = {read=GetTileName};
	int GetLocationIndex(char ident);
	int UndefindedId;
};
extern TMap Map;

#endif
