#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(wchar_t* filename, Graphics* gfx)
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