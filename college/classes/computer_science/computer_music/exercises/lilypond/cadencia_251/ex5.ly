superior =  {  \clef treble
	            \key c \major
	            \time 2/4
	  <f' d''>4 <d' b''>4 <e' c'''>2 
	}
	
	inferior =  { \clef bass
	              \key c \major
	              \time 2/4
	  
	  <a d'>4 <g g,>4 <g c'>2 
	}
	
	\score {
	  \new PianoStaff <<
	    \set PianoStaff.instrumentName = #"Piano  "
	    \new Staff = "superior" \superior
	    \new Staff = "inferior" \inferior
	  >>
	  
	  \layout { }	  
	  \midi { }
	}