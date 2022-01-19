singlePhaseTransportModel laminarTransport(U, phi);

   IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );
/*
// -------------------- Basic physical properties ------------------- //

dimensionedScalar rho1("rho1", dimDensity, transportProperties.lookup("rho1"));
dimensionedScalar rho2("rho2", dimDensity, transportProperties.lookup("rho2"));
dimensionedScalar nu("nu", dimViscosity, transportProperties.lookup("nu"));

dimensionedScalar pRef("pRef", dimensionSet(0,2,-2,0,0), transportProperties.lookup("pRef"));


// ------------------- Thermo physical properties ------------------- //

dimensionedScalar Cp1("Cp1", dimensionSet(0,2,-2,-1,0), transportProperties.lookup("Cp1"));
dimensionedScalar Cp2("Cp2", dimensionSet(0,2,-2,-1,0), transportProperties.lookup("Cp2"));

dimensionedScalar kappa1("kappa1", dimensionSet(1,1,-3,-1,0), transportProperties.lookup("kappa1"));
dimensionedScalar kappa2("kappa2", dimensionSet(1,1,-3,-1,0), transportProperties.lookup("kappa2"));

dimensionedScalar beta("beta", dimensionSet(0, 0, 0, -1, 0), transportProperties.lookup("beta"));
dimensionedScalar TRef("TRef", dimTemperature, transportProperties.lookup("TRef"));

dimensionedScalar Tmelt("Tmelt", dimTemperature, transportProperties.lookup("Tmelt"));
dimensionedScalar Tliq("Tliq", dimTemperature, transportProperties.lookup("Tliq"));
dimensionedScalar Tsol("Tsol", dimTemperature, transportProperties.lookup("Tsol"));

dimensionedScalar Lv("Lv", dimensionSet(0,2,-2,0,0), transportProperties.lookup("Lv"));


// -------------------- Heat transfer properties -------------------- //

dimensionedScalar Pr("Pr", dimless, transportProperties.lookup("Pr"));
dimensionedScalar Prt("Prt", dimless, transportProperties.lookup("Prt"));


// -------------------- Mass transfer properties -------------------- //

dimensionedScalar Dt("Dt", dimArea/dimTime, transportProperties.lookup("Dt"));
dimensionedScalar Lm("Lm", dimensionSet(1,-3,-1,0,0), transportProperties.lookup("Lm"));
//dimensionedScalar hm("hm", dimensionSet(1,-3,-1,0,0), transportProperties.lookup("hm"));

dimensionedScalar ySat("ySat", dimless, transportProperties.lookup("ySat"));


// ------------------ Momentum transfer properties ------------------ //

dimensionedScalar Cu("Cu", dimDensity/dimTime, transportProperties.lookup("Cu"));
dimensionedScalar q("q", dimless, transportProperties.lookup("q"));


// ----------------------- Geometric properties --------------------- //

dimensionedScalar L("L", dimLength, transportProperties.lookup("L"));
*/

dimensionedScalar nu("nu", dimViscosity, transportProperties.lookup("nu"));

dimensionedScalar TRef("TRef", dimTemperature, transportProperties.lookup("TRef"));
dimensionedScalar beta("beta", dimensionSet(0, 0, 0, -1, 0), transportProperties.lookup("beta"));
dimensionedScalar Pr("Pr", dimless, transportProperties.lookup("Pr"));
dimensionedScalar Prt("Prt", dimless, transportProperties.lookup("Prt"));
dimensionedScalar Dt1("Dt1", dimArea/dimTime, transportProperties.lookup("Dt1"));
dimensionedScalar Dt2("Dt2", dimArea/dimTime, transportProperties.lookup("Dt2"));
dimensionedScalar ySat("ySat", dimless, transportProperties.lookup("ySat"));
dimensionedScalar Lv("Lv", dimless, transportProperties.lookup("Lv"));

dimensionedScalar Cu("Cu", dimless/dimTime, transportProperties.lookup("Cu"));
dimensionedScalar q("q", dimless, transportProperties.lookup("q"));
