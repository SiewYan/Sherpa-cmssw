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
  class SSS1_Calculator: public Lorentz_Calculator {
  public:
    
    SSS1_Calculator(const Vertex_Key &key):
      Lorentz_Calculator(key) {}

    std::string Label() const { return "SSS1"; }

    CObject *Evaluate(const CObject_Vector &jj)
    {

// if outgoind UFO-index is 0
if (p_v->V()->id.back()==0){
const CScalar <SType> & j1 = *(jj[0]->Get< CScalar <SType> >());
const CScalar <SType> & j2 = *(jj[1]->Get< CScalar <SType> >());
CScalar<SType>* j0 = NULL;
j0 = CScalar<SType>::New((j1[0]) * (j2[0]));
j0->SetS(j1.S()|j2.S());
return j0;

}

// if outgoind UFO-index is 1
if (p_v->V()->id.back()==1){
const CScalar <SType> & j0 = *(jj[1]->Get< CScalar <SType> >());
const CScalar <SType> & j2 = *(jj[0]->Get< CScalar <SType> >());
CScalar<SType>* j1 = NULL;
j1 = CScalar<SType>::New((j0[0]) * (j2[0]));
j1->SetS(j0.S()|j2.S());
return j1;

}

// if outgoind UFO-index is 2
if (p_v->V()->id.back()==2){
const CScalar <SType> & j0 = *(jj[0]->Get< CScalar <SType> >());
const CScalar <SType> & j1 = *(jj[1]->Get< CScalar <SType> >());
CScalar<SType>* j2 = NULL;
j2 = CScalar<SType>::New((j0[0]) * (j1[0]));
j2->SetS(j0.S()|j1.S());
return j2;

}

    }

  };// end of class SSS1_Calculator

  template class SSS1_Calculator<double>;

}// end of namespace METOOLS

using namespace METOOLS;

DECLARE_GETTER(SSS1_Calculator<double>,"DSSS1",
	       Lorentz_Calculator,Vertex_Key);
Lorentz_Calculator *ATOOLS::Getter
<Lorentz_Calculator,Vertex_Key,SSS1_Calculator<double> >::
operator()(const Vertex_Key &key) const
{ return new SSS1_Calculator<double>(key); }

void ATOOLS::Getter<Lorentz_Calculator,Vertex_Key,
		    SSS1_Calculator<double> >::
PrintInfo(std::ostream &str,const size_t width) const
{ str<<"SSS1 vertex"; }
