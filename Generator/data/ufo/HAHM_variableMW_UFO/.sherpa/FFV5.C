#include "METOOLS/Explicit/Lorentz_Calculator.H"
#include "METOOLS/Currents/C_Scalar.H"
#include "METOOLS/Currents/C_Spinor.H"
#include "METOOLS/Currents/C_Vector.H"
#include "METOOLS/Explicit/Vertex.H"
#include "MODEL/Main/Single_Vertex.H"
#include "ATOOLS/Org/Message.H"
#include "ATOOLS/Org/Exception.H"

typedef std::complex<double> complex;

namespace METOOLS {

  template <typename SType>
  class FFV5_Calculator: public Lorentz_Calculator {
  public:
    
    FFV5_Calculator(const Vertex_Key &key):
      Lorentz_Calculator(key) {}

    std::string Label() const { return "FFV5"; }

    CObject *Evaluate(const CObject_Vector &jj)
    {

// if outgoind UFO-index is 0
if (p_v->V()->id.back()==0){
const CSpinor <SType> & j1 = ((jj[0]->Get< CSpinor <SType> >())->B() == -1) ? (*(jj[0]->Get< CSpinor <SType> >())) : (*(jj[0]->Get< CSpinor <SType> >())).CConj() ;
const ATOOLS::Vec4D & p1 = p_v->J(0)->P();
const CVec4 <SType> & j2 = *(jj[1]->Get< CVec4 <SType> >());
const ATOOLS::Vec4D & p2 = p_v->J(1)->P();
ATOOLS::Vec4D p0 = -p1-p2;
CSpinor<SType>* j0 = NULL;
switch(+(j1.On()<<(2))){
case 4:
j0 = CSpinor<SType>::New(m_r[0],-1,0,0,0,0,2);
(*j0)[0] = 0.0;
(*j0)[1] = 0.0;
(*j0)[2] = (4.0) * ((j1[0]) * (j2[0]) - ((j1[1]) * (j2[ATOOLS::Spinor<SType>::R1()]))) + (complex(-0.0,-4.0)) * ((j1[1]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (-4.0) * ((j1[0]) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j0)[3] = (4.0) * ((j1[1]) * (j2[0]) - ((j1[0]) * (j2[ATOOLS::Spinor<SType>::R1()]))) + (complex(0.0,4.0)) * ((j1[0]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (4.0) * ((j1[1]) * (j2[ATOOLS::Spinor<SType>::R3()]));
j0->SetS(j1.S()|j2.S());
return j0;
case 8:
j0 = CSpinor<SType>::New(m_r[0],-1,0,0,0,0,1);
(*j0)[0] = (j1[2]) * (j2[0]) + (j1[3]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (complex(0.0,1.0)) * ((j1[3]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (j1[2]) * (j2[ATOOLS::Spinor<SType>::R3()]);
(*j0)[1] = (j1[3]) * (j2[0]) + (j1[2]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (complex(-0.0,-1.0)) * ((j1[2]) * (j2[ATOOLS::Spinor<SType>::R2()])) - ((j1[3]) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j0)[2] = 0.0;
(*j0)[3] = 0.0;
j0->SetS(j1.S()|j2.S());
return j0;
case 12:
j0 = CSpinor<SType>::New(m_r[0],-1,0,0,0,0,3);
(*j0)[0] = (j1[2]) * (j2[0]) + (j1[3]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (complex(0.0,1.0)) * ((j1[3]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (j1[2]) * (j2[ATOOLS::Spinor<SType>::R3()]);
(*j0)[1] = (j1[3]) * (j2[0]) + (j1[2]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (complex(-0.0,-1.0)) * ((j1[2]) * (j2[ATOOLS::Spinor<SType>::R2()])) - ((j1[3]) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j0)[2] = (4.0) * ((j1[0]) * (j2[0]) - ((j1[1]) * (j2[ATOOLS::Spinor<SType>::R1()]))) + (complex(-0.0,-4.0)) * ((j1[1]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (-4.0) * ((j1[0]) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j0)[3] = (4.0) * ((j1[1]) * (j2[0]) - ((j1[0]) * (j2[ATOOLS::Spinor<SType>::R1()]))) + (complex(0.0,4.0)) * ((j1[0]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (4.0) * ((j1[1]) * (j2[ATOOLS::Spinor<SType>::R3()]));
j0->SetS(j1.S()|j2.S());
return j0;
default:
 THROW(fatal_error, "Massless spinor optimization error in Lorentz calculator");
}

}

// if outgoind UFO-index is 1
if (p_v->V()->id.back()==1){
const CSpinor <SType> & j0 = ((jj[1]->Get< CSpinor <SType> >())->B() == 1) ? (*(jj[1]->Get< CSpinor <SType> >())) : (*(jj[1]->Get< CSpinor <SType> >())).CConj() ;
const ATOOLS::Vec4D & p0 = p_v->J(1)->P();
const CVec4 <SType> & j2 = *(jj[0]->Get< CVec4 <SType> >());
const ATOOLS::Vec4D & p2 = p_v->J(0)->P();
ATOOLS::Vec4D p1 = -p0-p2;
CSpinor<SType>* j1 = NULL;
switch(+(j0.On()<<(0))){
case 1:
j1 = CSpinor<SType>::New(m_r[1],1,0,0,0,0,2);
(*j1)[0] = 0.0;
(*j1)[1] = 0.0;
(*j1)[2] = (j0[0]) * (j2[0]) + (j0[1]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (complex(-0.0,-1.0)) * ((j0[1]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (j0[0]) * (j2[ATOOLS::Spinor<SType>::R3()]);
(*j1)[3] = (j0[1]) * (j2[0]) + (j0[0]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (complex(0.0,1.0)) * ((j0[0]) * (j2[ATOOLS::Spinor<SType>::R2()])) - ((j0[1]) * (j2[ATOOLS::Spinor<SType>::R3()]));
j1->SetS(j0.S()|j2.S());
return j1;
case 2:
j1 = CSpinor<SType>::New(m_r[1],1,0,0,0,0,1);
(*j1)[0] = (4.0) * ((j0[2]) * (j2[0]) - ((j0[3]) * (j2[ATOOLS::Spinor<SType>::R1()]))) + (complex(0.0,4.0)) * ((j0[3]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (-4.0) * ((j0[2]) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j1)[1] = (4.0) * ((j0[3]) * (j2[0]) - ((j0[2]) * (j2[ATOOLS::Spinor<SType>::R1()]))) + (complex(-0.0,-4.0)) * ((j0[2]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (4.0) * ((j0[3]) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j1)[2] = 0.0;
(*j1)[3] = 0.0;
j1->SetS(j0.S()|j2.S());
return j1;
case 3:
j1 = CSpinor<SType>::New(m_r[1],1,0,0,0,0,3);
(*j1)[0] = (4.0) * ((j0[2]) * (j2[0]) - ((j0[3]) * (j2[ATOOLS::Spinor<SType>::R1()]))) + (complex(0.0,4.0)) * ((j0[3]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (-4.0) * ((j0[2]) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j1)[1] = (4.0) * ((j0[3]) * (j2[0]) - ((j0[2]) * (j2[ATOOLS::Spinor<SType>::R1()]))) + (complex(-0.0,-4.0)) * ((j0[2]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (4.0) * ((j0[3]) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j1)[2] = (j0[0]) * (j2[0]) + (j0[1]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (complex(-0.0,-1.0)) * ((j0[1]) * (j2[ATOOLS::Spinor<SType>::R2()])) + (j0[0]) * (j2[ATOOLS::Spinor<SType>::R3()]);
(*j1)[3] = (j0[1]) * (j2[0]) + (j0[0]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (complex(0.0,1.0)) * ((j0[0]) * (j2[ATOOLS::Spinor<SType>::R2()])) - ((j0[1]) * (j2[ATOOLS::Spinor<SType>::R3()]));
j1->SetS(j0.S()|j2.S());
return j1;
default:
 THROW(fatal_error, "Massless spinor optimization error in Lorentz calculator");
}

}

// if outgoind UFO-index is 2
if (p_v->V()->id.back()==2){
const CSpinor <SType> & j0 = ((jj[0]->Get< CSpinor <SType> >())->B() == 1) ? (*(jj[0]->Get< CSpinor <SType> >())) : (*(jj[0]->Get< CSpinor <SType> >())).CConj() ;
const ATOOLS::Vec4D & p0 = p_v->J(0)->P();
const CSpinor <SType> & j1 = ((jj[1]->Get< CSpinor <SType> >())->B() == -1) ? (*(jj[1]->Get< CSpinor <SType> >())) : (*(jj[1]->Get< CSpinor <SType> >())).CConj() ;
const ATOOLS::Vec4D & p1 = p_v->J(1)->P();
ATOOLS::Vec4D p2 = -p0-p1;
CVec4<SType>* j2 = NULL;
switch(+(j0.On()<<(0))+(j1.On()<<(2))){
case 5:
return j2;
case 6:
j2 = CVec4<SType>::New();
(*j2)[0] = (4.0) * ((j0[2]) * (j1[0]) + (j0[3]) * (j1[1]));
(*j2)[ATOOLS::Spinor<SType>::R1()] = (4.0) * ((j0[3]) * (j1[0]) + (j0[2]) * (j1[1]));
(*j2)[ATOOLS::Spinor<SType>::R2()] = (complex(0.0,-4.0)) * ((j0[3]) * (j1[0]) - ((j0[2]) * (j1[1])));
(*j2)[ATOOLS::Spinor<SType>::R3()] = (4.0) * ((j0[2]) * (j1[0]) - ((j0[3]) * (j1[1])));
j2->SetS(j0.S()|j1.S());
return j2;
case 7:
j2 = CVec4<SType>::New();
(*j2)[0] = (4.0) * ((j0[2]) * (j1[0]) + (j0[3]) * (j1[1]));
(*j2)[ATOOLS::Spinor<SType>::R1()] = (4.0) * ((j0[3]) * (j1[0]) + (j0[2]) * (j1[1]));
(*j2)[ATOOLS::Spinor<SType>::R2()] = (complex(0.0,-4.0)) * ((j0[3]) * (j1[0]) - ((j0[2]) * (j1[1])));
(*j2)[ATOOLS::Spinor<SType>::R3()] = (4.0) * ((j0[2]) * (j1[0]) - ((j0[3]) * (j1[1])));
j2->SetS(j0.S()|j1.S());
return j2;
case 9:
j2 = CVec4<SType>::New();
(*j2)[0] = (j0[0]) * (j1[2]) + (j0[1]) * (j1[3]);
(*j2)[ATOOLS::Spinor<SType>::R1()] = -((j0[1]) * (j1[2]) + (j0[0]) * (j1[3]));
(*j2)[ATOOLS::Spinor<SType>::R2()] = (complex(0.0,1.0)) * ((j0[1]) * (j1[2]) - ((j0[0]) * (j1[3])));
(*j2)[ATOOLS::Spinor<SType>::R3()] = -((j0[0]) * (j1[2]) - ((j0[1]) * (j1[3])));
j2->SetS(j0.S()|j1.S());
return j2;
case 10:
return j2;
case 11:
j2 = CVec4<SType>::New();
(*j2)[0] = (j0[0]) * (j1[2]) + (j0[1]) * (j1[3]);
(*j2)[ATOOLS::Spinor<SType>::R1()] = -((j0[1]) * (j1[2]) + (j0[0]) * (j1[3]));
(*j2)[ATOOLS::Spinor<SType>::R2()] = (complex(0.0,1.0)) * ((j0[1]) * (j1[2]) - ((j0[0]) * (j1[3])));
(*j2)[ATOOLS::Spinor<SType>::R3()] = -((j0[0]) * (j1[2]) - ((j0[1]) * (j1[3])));
j2->SetS(j0.S()|j1.S());
return j2;
case 13:
j2 = CVec4<SType>::New();
(*j2)[0] = (j0[0]) * (j1[2]) + (j0[1]) * (j1[3]);
(*j2)[ATOOLS::Spinor<SType>::R1()] = -((j0[1]) * (j1[2]) + (j0[0]) * (j1[3]));
(*j2)[ATOOLS::Spinor<SType>::R2()] = (complex(0.0,1.0)) * ((j0[1]) * (j1[2]) - ((j0[0]) * (j1[3])));
(*j2)[ATOOLS::Spinor<SType>::R3()] = -((j0[0]) * (j1[2]) - ((j0[1]) * (j1[3])));
j2->SetS(j0.S()|j1.S());
return j2;
case 14:
j2 = CVec4<SType>::New();
(*j2)[0] = (4.0) * ((j0[2]) * (j1[0]) + (j0[3]) * (j1[1]));
(*j2)[ATOOLS::Spinor<SType>::R1()] = (4.0) * ((j0[3]) * (j1[0]) + (j0[2]) * (j1[1]));
(*j2)[ATOOLS::Spinor<SType>::R2()] = (complex(0.0,-4.0)) * ((j0[3]) * (j1[0]) - ((j0[2]) * (j1[1])));
(*j2)[ATOOLS::Spinor<SType>::R3()] = (4.0) * ((j0[2]) * (j1[0]) - ((j0[3]) * (j1[1])));
j2->SetS(j0.S()|j1.S());
return j2;
case 15:
j2 = CVec4<SType>::New();
(*j2)[0] = (4.0) * ((j0[2]) * (j1[0]) + (j0[3]) * (j1[1])) + (j0[0]) * (j1[2]) + (j0[1]) * (j1[3]);
(*j2)[ATOOLS::Spinor<SType>::R1()] = (4.0) * ((j0[3]) * (j1[0]) + (j0[2]) * (j1[1])) + -((j0[1]) * (j1[2])) - ((j0[0]) * (j1[3]));
(*j2)[ATOOLS::Spinor<SType>::R2()] = (complex(0.0,-4.0)) * ((j0[3]) * (j1[0]) - ((j0[2]) * (j1[1]))) + (complex(0.0,1.0)) * ((j0[1]) * (j1[2])) + (complex(0.0,-1.0)) * ((j0[0]) * (j1[3]));
(*j2)[ATOOLS::Spinor<SType>::R3()] = (4.0) * ((j0[2]) * (j1[0]) - ((j0[3]) * (j1[1]))) + -((j0[0]) * (j1[2])) + (j0[1]) * (j1[3]);
j2->SetS(j0.S()|j1.S());
return j2;
default:
 THROW(fatal_error, "Massless spinor optimization error in Lorentz calculator");
}

}

    }

  };// end of class FFV5_Calculator

  template class FFV5_Calculator<double>;

}// end of namespace METOOLS

using namespace METOOLS;

DECLARE_GETTER(FFV5_Calculator<double>,"DFFV5",
	       Lorentz_Calculator,Vertex_Key);
Lorentz_Calculator *ATOOLS::Getter
<Lorentz_Calculator,Vertex_Key,FFV5_Calculator<double> >::
operator()(const Vertex_Key &key) const
{ return new FFV5_Calculator<double>(key); }

void ATOOLS::Getter<Lorentz_Calculator,Vertex_Key,
		    FFV5_Calculator<double> >::
PrintInfo(std::ostream &str,const size_t width) const
{ str<<"FFV5 vertex"; }
