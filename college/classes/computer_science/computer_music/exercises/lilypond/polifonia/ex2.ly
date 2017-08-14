\version "2.16.2" 

\header { 
  %title    = \markup { \fontsize #0.1 "Bach (Coral No. 6,  BWV 650)" } 
  %subtitle = \markup { \fontsize #1.0 "Acústica Musical 1 (Orquestração) " } 
  %subsubtitle = \markup { \fontsize #1.0 "UnB / Acústica Musical 1 (Orquestração) " } 

piece = \markup { \fontsize #1 \bold "J. S. Bach (Coral No. 6,  BWV 650)" }
opus  = \markup { \italic "BWV 650" }

%composer = "J. S. Bach" 
%copyright = "Domínio público" 
tagline = ##f 
} 

 
melodiaA = { \clef treble
	    \key  f \major
	    \time 4/4	
	    \tempo 4 = 72
	    r2 r4 f'4     a'4 g'4 a'4 bes'4   c''2 a'4\fermata	s4    	         
	  }
	
melodiaB = { \clef treble
	    \key  f \major
	    \time 4/4	
	    r2 r4 c'4    f'4 g'4 f'4 f'4    e'8 f'8 g'8 e'8 f'4\fermata  s4 
	   }
		  	   	   
melodiaC = { \clef alto
	    \key  f \major
	    \time 4/4	
	    \tempo 4 = 72
	    r2 r4 a4     c'4 c'4 c'4 d'4   g4 c'4 c'4	\fermata s4    	         
	  }
	
melodiaD = { \clef bass
	    \key  f \major
	    \time 4/4	
	    r2 r4 f,4    f4 e4 ees4 d4    c8 d8 e8 c8 f4 \fermata s4 	     
	   }
		  
\score 
{ 
  <<
    <<
	  \new Staff \with { instrumentName = "Flauta" }
	  << \set Staff.midiInstrument = #"flute"
	    \new Voice = "primeira"
	     { \melodiaA           	      
	     }	      
	  >>	  
	  	  
	  \new Staff \with { instrumentName = "Corne Inglês" }
	  << \set Staff.midiInstrument = #"english horn"	   
	      \new Voice= "segunda"
	      { \melodiaB
	      }
	  >>	  
	  		  
	  \new Staff \with { instrumentName = "Viola" }
	  << \set Staff.midiInstrument = #"viola"
	    \new Voice = "terceira"
	      { \melodiaC           	      
	      }	     
	  >>
        	
	  \new Staff \with { instrumentName = "Violoncelo" }
	  << \set Staff.midiInstrument = #"cello"	    
	      \new Voice= "quarta"
	      { \melodiaD
	      }
	  >>
        		
      >>
  >>
			
    \layout { }	  
    \midi { }
 }      