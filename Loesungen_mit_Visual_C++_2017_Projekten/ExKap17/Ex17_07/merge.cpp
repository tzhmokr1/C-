// -------------------------------------------------------------
// merge.cpp
// Definiert die Funktion merge(), die zwei 
// in aufsteigender Reihenfolge sortierte Vektoren mischt.
// -------------------------------------------------------------

// -------------------------------------------------------------
// Die Funktion isSorted() 
// Return-Wert: true, falls der Vektor in aufsteigender 
//              Reihenfolge sorteirt ist, sonst  false. 
//
bool isSorted( int arr[], int len)
{
    for( int *p = arr; p < arr + len-1;  ++p)
        if( *p > *(p+1) )
            return false;

    return true;
}

// -----------------------------------------------------------------
// Die Funktion merge() 
// Return-Wert: Länge des Ergebnisvektors bzw.  -1, falls ein Vektor
//              nicht in aufsteigender Reihenfolge sortiert war. 
//
int merge( int arr1[], int len1, int arr2[], int len2, int dest[])
{
   int *p1 = arr1, *p2 = arr2, *p3 = dest;

   if( !isSorted( arr1, len1) || !isSorted(arr2, len2))
       return -1;
   
   for(  ; p1 < arr1+len1  &&  p2 < arr2+len2; ++p3 )
   {
      if( *p1 <= *p2)
      { *p3 = *p1;  ++p1; }
      else
      { *p3 = *p2;  ++p2; }
   }

   // Kopiert restliche Elemente aus arr1 bzw. arr2:
   while( p1 < arr1+len1)
       *p3++ = *p1++;

   while( p2 < arr2+len2)
       *p3++ = *p1++;

   return (p3 - dest);
}
