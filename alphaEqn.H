{
    int iter = 0;
    scalar residual = 1;
    scalar meanResidual = 1;

    const dictionary& meltDict = mesh.solutionDict().subDict("subdict");
    int minTCorr(readLabel(meltDict.lookup("minTempCorr")));
    int maxTCorr(readLabel(meltDict.lookup("maxTempCorr")));
    scalar alphaTol(readScalar(meltDict.lookup("alphaTol")));
    scalar alphaRel(readScalar(meltDict.lookup("alphaRelax")));

    const dimensionedScalar dumt("1", dimensionSet(0,0,1,0,0,0,0), 1);


	Dt = alpha1*Dt1 + alpha2*Dt2;

	fvScalarMatrix alphaEqn
	(
	    fvm::div(phi, Y)
	  - fvm::laplacian(Dt1, Y)

//	  + fvc::ddt(alpha1)
//	  + fvc::div(phi, alpha1)
//	  - fvc::laplacian(Dt, alpha1)
/*
	 ==

	  - fvm::Sp(alpha1/dumt, Y)
*/
	);

//	alphaEqn.relax();
	alphaEqn.solve();

	solve(alphaEqn == -fvc::Sp((Y - YSat),Y)/dumt);

	massFlux += Lv*(Y - YSat);

//	alpha1 = max(min(alpha1 + Lv*(Y - YSat)/917, scalar(1)), scalar(0));

	alpha1 = max(min(alpha1 + massFlux/917, scalar(1)), scalar(0));
	alpha2 = scalar(1) - alpha1;

//	rhof += Lv*(Y - YSat);
	rhof = alpha2*917;

//	massFlux.max(0);

	xf += rhof/917;

//	xf = -xf;

	xf.max(0);
	rhof.max(0);

    Dc = Cu*pow(alpha2,2)/(pow(alpha1,3)+q);
}
