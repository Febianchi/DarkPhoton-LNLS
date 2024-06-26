#include "PrimaryGeneratorAction.hh"

#include <random>

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);

    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName="e+";
    G4ParticleDefinition *particle = particleTable->FindParticle("e+");

    G4double randomX = rand() % 10;
    G4double randomY = rand() % 10;

    G4double posX = randomX/10.*cm;
    G4double posY = randomY/10.*cm;

    G4ThreeVector pos(posX, posY,-3.25*m); //G4ThreeVector pos(posX*m, posY*m,-1*m);
    G4ThreeVector mom(0.,0.,1);

    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(550.*MeV);
    fParticleGun->SetParticleDefinition(particle);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
