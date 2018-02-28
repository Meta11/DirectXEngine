#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const wchar_t* filename, Renderer* gfx)
{
	this->gfx = gfx;
	bmp = nullptr;
	HRESULT hr;
	//create wic factory
	IWICImagingFactory* wicFactory = nullptr;
	hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&wicFactory);
	//create a decoder
	IWICBitmapDecoder* wicDecoder = nullptr;
	hr = wicFactory->CreateDecoderFromFilename(filename, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &wicDecoder);
	//read frames (for animation)
	IWICBitmapFrameDecode* wicFrame = nullptr;
	hr = wicDecoder->GetFrame(0, &wicFrame);
	//create a converter wic->d2d
	IWICFormatConverter* wicConverter = nullptr;
	hr = wicFactory->CreateFormatConverter(&wicConverter);
	//setup the converter
	hr = wicConverter->Initialize(wicFrame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0, WICBitmapPaletteTypeCustom);
	//use it to convert it to d2dbitmap
	gfx->getRenderTarget()->CreateBitmapFromWicBitmap(wicConverter, NULL, &bmp);
	//free memory when finished
	if (wicConverter) wicConverter->Release();
	if (wicFrame) wicFrame->Release();
	if (wicDecoder) wicDecoder->Release();
	if (wicFactory) wicFactory->Release();

	spriteWidth = bmp->GetSize().width;
	spriteHeight = bmp->GetSize().height;
	spritesAcross = 1;
}

SpriteSheet::SpriteSheet(const wchar_t* filename, Renderer* gfx, int spriteWidth, int spriteHeight) : SpriteSheet(filename, gfx)
{
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->spritesAcross = bmp->GetSize().width / spriteWidth;
}

SpriteSheet::~SpriteSheet()
{
	if (bmp) bmp->Release();
}
void SpriteSheet::draw()
{
	gfx->getRenderTarget()->DrawBitmap(bmp, D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height), 1.0f, 
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height));
}

void SpriteSheet::draw(Vector3D position, int index, int row)
{
	D2D_RECT_F src = D2D1::RectF(
		(float)((index % spritesAcross) * spriteWidth),
		(float)((index / spritesAcross + row) * spriteHeight),
		(float)((index % spritesAcross) * spriteWidth) + spriteWidth,
		(float)((index / spritesAcross + row) * spriteHeight) + spriteHeight);

	D2D_RECT_F dest = D2D1::RectF(position.x, position.y, position.x + spriteWidth, position.y + spriteHeight);

	gfx->getRenderTarget()->DrawBitmap(bmp, dest, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, src);
}