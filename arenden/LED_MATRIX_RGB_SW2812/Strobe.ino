void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause){

  for(int j = 0; j < StrobeCount; j++) {
    setAll(red,green,blue);
    showStrip();
    delay(FlashDelay);
    setAll(0,0,0);
    showStrip();
    delay(FlashDelay);
  }

 delay(EndPause);
}
