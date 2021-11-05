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
  class VVVV3_Calculator: public Lorentz_Calculator {
  public:
    
    VVVV3_Calculator(const Vertex_Key &key):
      Lorentz_Calculator(key) {}

    std::string Label() const { return "VVVV3"; }

    CObject *Evaluate(const CObject_Vector &jj)
    {

// if outgoind UFO-index is 0
if (p_v->V()->id.back()==0){
const CVec4 <SType> & j1 = *(jj[0]->Get< CVec4 <SType> >());
const CVec4 <SType> & j2 = *(jj[1]->Get< CVec4 <SType> >());
const CVec4 <SType> & j3 = *(jj[2]->Get< CVec4 <SType> >());
CVec4<SType>* j0 = NULL;
j0 = CVec4<SType>::New();
(*j0)[0] = -(((j1[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R1()]) + (j1[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R2()]) + (j1[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R3()])) * (j3[0]) - (((j1[0]) * (j2[ATOOLS::Spinor<SType>::R1()])) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j1[0]) * (j2[ATOOLS::Spinor<SType>::R2()])) * (j3[ATOOLS::Spinor<SType>::R2()])) - (((j1[0]) * (j2[ATOOLS::Spinor<SType>::R3()])) * (j3[ATOOLS::Spinor<SType>::R3()])));
(*j0)[ATOOLS::Spinor<SType>::R1()] = -(((j1[ATOOLS::Spinor<SType>::R1()]) * (j2[0])) * (j3[0]) - (((j1[0]) * (j2[0]) - ((j1[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R2()])) - ((j1[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j1[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R2()])) * (j3[ATOOLS::Spinor<SType>::R2()])) - (((j1[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R3()])) * (j3[ATOOLS::Spinor<SType>::R3()])));
(*j0)[ATOOLS::Spinor<SType>::R2()] = -(((j1[ATOOLS::Spinor<SType>::R2()]) * (j2[0])) * (j3[0]) - (((j1[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R1()])) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j1[0]) * (j2[0]) - ((j1[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R1()])) - ((j1[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R2()])) - (((j1[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R3()])) * (j3[ATOOLS::Spinor<SType>::R3()])));
(*j0)[ATOOLS::Spinor<SType>::R3()] = -(((j1[ATOOLS::Spinor<SType>::R3()]) * (j2[0])) * (j3[0]) - (((j1[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R1()])) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j1[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R2()])) * (j3[ATOOLS::Spinor<SType>::R2()])) - (((j1[0]) * (j2[0]) - ((j1[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R1()])) - ((j1[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R2()]))) * (j3[ATOOLS::Spinor<SType>::R3()])));
j0->SetS(j1.S()|j2.S()|j3.S());
return j0;

}

// if outgoind UFO-index is 1
if (p_v->V()->id.back()==1){
const CVec4 <SType> & j0 = *(jj[2]->Get< CVec4 <SType> >());
const CVec4 <SType> & j2 = *(jj[0]->Get< CVec4 <SType> >());
const CVec4 <SType> & j3 = *(jj[1]->Get< CVec4 <SType> >());
CVec4<SType>* j1 = NULL;
j1 = CVec4<SType>::New();
(*j1)[0] = -(((j0[ATOOLS::Spinor<SType>::R1()]) * (j2[0]) - ((j0[0]) * (j2[ATOOLS::Spinor<SType>::R1()]))) * (j3[ATOOLS::Spinor<SType>::R1()]) + ((j0[ATOOLS::Spinor<SType>::R2()]) * (j2[0]) - ((j0[0]) * (j2[ATOOLS::Spinor<SType>::R2()]))) * (j3[ATOOLS::Spinor<SType>::R2()]) + ((j0[ATOOLS::Spinor<SType>::R3()]) * (j2[0]) - ((j0[0]) * (j2[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R3()]));
(*j1)[ATOOLS::Spinor<SType>::R1()] = -(((j0[ATOOLS::Spinor<SType>::R1()]) * (j2[0]) - ((j0[0]) * (j2[ATOOLS::Spinor<SType>::R1()]))) * (j3[0]) + ((j0[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R1()]) - ((j0[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R2()]))) * (j3[ATOOLS::Spinor<SType>::R2()]) + ((j0[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R1()]) - ((j0[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R3()]));
(*j1)[ATOOLS::Spinor<SType>::R2()] = -(((j0[ATOOLS::Spinor<SType>::R2()]) * (j2[0]) - ((j0[0]) * (j2[ATOOLS::Spinor<SType>::R2()]))) * (j3[0]) - (((j0[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R1()]) - ((j0[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R2()]))) * (j3[ATOOLS::Spinor<SType>::R1()])) + ((j0[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R2()]) - ((j0[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R3()]));
(*j1)[ATOOLS::Spinor<SType>::R3()] = -(((j0[ATOOLS::Spinor<SType>::R3()]) * (j2[0]) - ((j0[0]) * (j2[ATOOLS::Spinor<SType>::R3()]))) * (j3[0]) - (((j0[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R1()]) - ((j0[ATOOLS::Spinor<SType>::R1()]) * (j2[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j0[ATOOLS::Spinor<SType>::R3()]) * (j2[ATOOLS::Spinor<SType>::R2()]) - ((j0[ATOOLS::Spinor<SType>::R2()]) * (j2[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R2()])));
j1->SetS(j0.S()|j2.S()|j3.S());
return j1;

}

// if outgoind UFO-index is 2
if (p_v->V()->id.back()==2){
const CVec4 <SType> & j0 = *(jj[1]->Get< CVec4 <SType> >());
const CVec4 <SType> & j1 = *(jj[2]->Get< CVec4 <SType> >());
const CVec4 <SType> & j3 = *(jj[0]->Get< CVec4 <SType> >());
CVec4<SType>* j2 = NULL;
j2 = CVec4<SType>::New();
(*j2)[0] = ((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R1()]) + (j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R2()]) + (j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R3()])) * (j3[0]) - (((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[0])) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[0])) * (j3[ATOOLS::Spinor<SType>::R2()])) - (((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[0])) * (j3[ATOOLS::Spinor<SType>::R3()]));
(*j2)[ATOOLS::Spinor<SType>::R1()] = ((j0[0]) * (j1[ATOOLS::Spinor<SType>::R1()])) * (j3[0]) - (((j0[0]) * (j1[0]) - ((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R2()])) - ((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R1()])) * (j3[ATOOLS::Spinor<SType>::R2()])) - (((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R1()])) * (j3[ATOOLS::Spinor<SType>::R3()]));
(*j2)[ATOOLS::Spinor<SType>::R2()] = ((j0[0]) * (j1[ATOOLS::Spinor<SType>::R2()])) * (j3[0]) - (((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R2()])) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j0[0]) * (j1[0]) - ((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R1()])) - ((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R3()]))) * (j3[ATOOLS::Spinor<SType>::R2()])) - (((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R2()])) * (j3[ATOOLS::Spinor<SType>::R3()]));
(*j2)[ATOOLS::Spinor<SType>::R3()] = ((j0[0]) * (j1[ATOOLS::Spinor<SType>::R3()])) * (j3[0]) - (((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R3()])) * (j3[ATOOLS::Spinor<SType>::R1()])) - (((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R3()])) * (j3[ATOOLS::Spinor<SType>::R2()])) - (((j0[0]) * (j1[0]) - ((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R1()])) - ((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R2()]))) * (j3[ATOOLS::Spinor<SType>::R3()]));
j2->SetS(j0.S()|j1.S()|j3.S());
return j2;

}

// if outgoind UFO-index is 3
if (p_v->V()->id.back()==3){
const CVec4 <SType> & j0 = *(jj[0]->Get< CVec4 <SType> >());
const CVec4 <SType> & j1 = *(jj[1]->Get< CVec4 <SType> >());
const CVec4 <SType> & j2 = *(jj[2]->Get< CVec4 <SType> >());
CVec4<SType>* j3 = NULL;
j3 = CVec4<SType>::New();
(*j3)[0] = ((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R1()]) + (j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R2()]) + (j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R3()])) * (j2[0]) - (((j0[0]) * (j1[ATOOLS::Spinor<SType>::R1()])) * (j2[ATOOLS::Spinor<SType>::R1()])) - (((j0[0]) * (j1[ATOOLS::Spinor<SType>::R2()])) * (j2[ATOOLS::Spinor<SType>::R2()])) - (((j0[0]) * (j1[ATOOLS::Spinor<SType>::R3()])) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j3)[ATOOLS::Spinor<SType>::R1()] = ((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[0])) * (j2[0]) - (((j0[0]) * (j1[0]) - ((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R2()])) - ((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R3()]))) * (j2[ATOOLS::Spinor<SType>::R1()])) - (((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R2()])) * (j2[ATOOLS::Spinor<SType>::R2()])) - (((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R3()])) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j3)[ATOOLS::Spinor<SType>::R2()] = ((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[0])) * (j2[0]) - (((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R1()])) * (j2[ATOOLS::Spinor<SType>::R1()])) - (((j0[0]) * (j1[0]) - ((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R1()])) - ((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R3()]))) * (j2[ATOOLS::Spinor<SType>::R2()])) - (((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R3()])) * (j2[ATOOLS::Spinor<SType>::R3()]));
(*j3)[ATOOLS::Spinor<SType>::R3()] = ((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[0])) * (j2[0]) - (((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R1()])) * (j2[ATOOLS::Spinor<SType>::R1()])) - (((j0[ATOOLS::Spinor<SType>::R3()]) * (j1[ATOOLS::Spinor<SType>::R2()])) * (j2[ATOOLS::Spinor<SType>::R2()])) - (((j0[0]) * (j1[0]) - ((j0[ATOOLS::Spinor<SType>::R1()]) * (j1[ATOOLS::Spinor<SType>::R1()])) - ((j0[ATOOLS::Spinor<SType>::R2()]) * (j1[ATOOLS::Spinor<SType>::R2()]))) * (j2[ATOOLS::Spinor<SType>::R3()]));
j3->SetS(j0.S()|j1.S()|j2.S());
return j3;

}

    }

  };// end of class VVVV3_Calculator

  template class VVVV3_Calculator<double>;

}// end of namespace METOOLS

using namespace METOOLS;

DECLARE_GETTER(VVVV3_Calculator<double>,"DVVVV3",
	       Lorentz_Calculator,Vertex_Key);
Lorentz_Calculator *ATOOLS::Getter
<Lorentz_Calculator,Vertex_Key,VVVV3_Calculator<double> >::
operator()(const Vertex_Key &key) const
{ return new VVVV3_Calculator<double>(key); }

void ATOOLS::Getter<Lorentz_Calculator,Vertex_Key,
		    VVVV3_Calculator<double> >::
PrintInfo(std::ostream &str,const size_t width) const
{ str<<"VVVV3 vertex"; }
