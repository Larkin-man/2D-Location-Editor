//---------------------------------------------------------------------------

#ifndef MapH
#define MapH
#include <vector>
//---------------------------------------------------------------------------
const size_t SYMBCOUNT = 4;
typedef char tileid[SYMBCOUNT];
typedef char tileidnl[SYMBCOUNT+1];
tileid const NoneTileStr = {"NONE"};
const int TILESIZE = 1024;

//const tileid NoneTile = {L"NONE"}; //TODO: рисуй его

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

struct MyPoint
{
	int x,y;
	MyPoint(int l, int t) {x=l;y=t; }
	//MyPoint() { }
};

class TMap
{
private:
	int FHeight, FWidth;

protected:
	tileidnl* GetTile(int i) const	{  return &Idents[i];   }
	String GetTileName(int i)
	{
	//char dd[5];
	//strncpy(dd, Idents[i], SYMBCOUNT);
	//dd[4] = '\0';
	 //String gg = file->Names[i];
	 //String ff =file->Values[dd];//нужен нулл в конце
	 //return ff;
	return 	file->Values[Idents[i]];
	}
public:

	tileidnl *Idents;
	TStringList *file;
	struct TSprite
	{
		//tileid Ident;
		TSprite(int index, int left, int top)
		{
			Index = index;
			x = left;
			y = top;
      }
		int Index;
		int x,y;   //Координаты верхнего левого угла
	} ;
	typedef struct
	{
		int Image;
		tileid Ident;
		unsigned char Radiation;
		unsigned char Anomally;
		int Variant;
		//Not save:
		TColor ColorRad;
		TColor ColorAnom;
		int Triggger;
		bool AnomTest;
		//TSprite *Sprites;
		std::vector<TSprite> Sprites;
		//int SprCount;
		///void ConvertIdent()	{	Image = GetLocationIndex(Ident); }
		void SetRadiation(int iRadiation);
		void SetAnomally(int iAnomally);
		void DeleteInPos(int x, int y);
	} TCell;
	void Create(int Width, int Height);    //init
	void Clear();
	__property int Width = {read=FWidth}; //0 - W-1
	__property int Height = {read=FHeight};
	TCell **Cell; //[W][H]
	bool DebugOpenTrig;
	void Destroy();
	__fastcall TMap();
	__fastcall ~TMap();
	static TColor GetAnomallyColor(int Power);
	static TColor GetRadiationColor(int Power);
	bool Open(AnsiString FileName); //Функция загружает список из бинарного файла
	bool Save(AnsiString FileName);
	void AnomallyRun();
	//Base Tiles
	void LoadTiles(const UnicodeString FileName);
	int TilesCount;
	__property tileidnl TileIdent[int i] = {read=GetTile};
	__property String TileName[int i] = {read=GetTileName};
	int GetLocationIndex(const tileid ident) const;
	int UndefindedId;
	int *Buttons; //При клике на кнопку тайла
	int *Variants; //При смене варианта указывает следующий
	//Спрайты
	TStringList *SpriteNames;
	int SpritesCount;
	void LoadSprites(const UnicodeString FileName);
	//MyPoint *SpriteSizes;
	TPicture **Sprites;
	std::vector<TSprite> SpritesList;
};
extern TMap Map;

#endif
