Function Main()

   ? IsFormat( "ABC123", "CCCNNN" )
   ? IsFormat( "123ABC", "CCCNNN" )
   ? IsFormat( "ABC123", "???NNN" )
   ? IsFormat( "ABC123", "CCC???" )
   ? IsFormat( "A C1 3", "C CN N" )

Return( NIL )
