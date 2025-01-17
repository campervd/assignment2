//
// Created by Keith Van Dyke on 10/04/19
//

#include "Sleigh.h"

Sleigh::Sleigh(string brand, string model, string fuelType, int numReindeer) {
    setBrand(brand);
    setModel(model);
    setReindeerCount(numReindeer);
    setFuelType(fuelType);
}

Sleigh::~Sleigh() = default;

int Sleigh::getReindeerCount() {
    return numberOfReindeer;
}

void Sleigh::setReindeerCount(int numReindeer) {
    numberOfReindeer = numReindeer;
}

double Sleigh::mileageEstimate(double time) {
    double mileage = 1000 * time;
    if (fuelType != "carrots" && numberOfReindeer < 8) {
        mileage -= (mileage * 0.30) * (8 - numberOfReindeer);  //30% decrease in speed per missing
    }                                                     //reindeer if not eating carrots
    else if (fuelType == "carrots" && numberOfReindeer < 8) {
        mileage -= (mileage * 0.15) * (8 - numberOfReindeer);  //15% decrease in speed per missing
    }                                                     //reindeer if eating carrots
    if (mileage < 0) {
        return 0;
    }
    return mileage;
}

string Sleigh::toString() {
    return "-> Sleigh\n" + PoweredVehicle::toString() + "\n\tReindeer: " +
           to_string(numberOfReindeer);
}
