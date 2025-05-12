#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <vector>          //NEURAL NET IMPLEMENTATION IN C++ -  YOUTUBE  (I was curious about networks)
using namespace std;       //54:20 update input weights

struct Connection{
	double weight;
	double deltaWeight;
};

class Neuron;

typedef vector<Neuron> Layer;

//********************** class Neuron ***********************************//
	class Neuron{
		public: 
			Neuron(unsigned numOutputs, unsigned myIndex);
			void setOutputVal(double val) { m_outputVal = val;}
			double getOutputVal(void) const {return m_outputVal;}
			void feedForward( const Layer &prevLayer);
			void calcOutputGradients(double targetVal);
			void calcHiddenGradients(const Layer &nextLayer);
			void updateInputWeights(Layer &prevLayer);

		private:
			static double transferFunction( double x);
			static double transferFunctionDerivative( double x);
			static double randomWeight(void) { return rand() / double(RAND_MAX);}
			double sumDOW(const Layer &nextLayer) const;
			double m_outputVal;
			vector<Connection> m_outputWeights;
			unsigned m_myIndex;
			double m_gradient;

	};

	void Neuron :: updateInputWeights(Layer &prevLayer){

		//the weights to be updated are in the connection container
		//in the neurons in the preceding layer


	}

	double Neuron :: sumDOW (const Layer &nextLayer) const {

		double sum = 0.0;

		//sum of our contributions of the errors at the nodes we feed
		for (unsigned n = 0; n < nextLayer.size() - 1; ++n){
			sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
		}

		return sum;
	}

	void Neuron :: calcHiddenGradients(const Layer &nextLayer){

		double dow = sumDOW(nextLayer);
		m_gradient = dow * Neuron::transferFunctionDerivative(m_outputVal);
	}


	void Neuron :: calcOutputGradients(double targetVal){
		
		double delta = targetVal - m_outputVal;
		m_gradient = delta * Neuron::transferFunctionDerivative(m_outputVal);
	}

	double Neuron :: transferFunction( double x){

		//tanh - output range [-1.0......1.0]
		return tanh(x);
	}

	double transferFunctionDerivative( double x){

		//tanh derivative approx
		return 1.0 - x * x;
	}


	void Neuron :: feedForward( const Layer &prevLayer){

		double sum = 0.0;

		//sum the previous layer's outputs (which are out inputs)
		//include the  bias node from the previous later

		for ( unsigned n = 0; n < prevLayer.size(); ++n){
			sum += prevLayer[n].m_outputVal * prevLayer[n].m_outputWeights[m_myIndex].weight;
		}

		m_outputVal = Neuron :: transferFunction(sum);

	}

	Neuron :: Neuron(unsigned numOutputs, unsigned myIndex){
		for (unsigned c = 0; c < numOutputs; ++c ){
			m_outputWeights.push_back(Connection());
			m_outputWeights.back().weight = randomWeight();
		}

		m_myIndex = myIndex;
	}
//********************** class Net ***********************************//
	class Net{
		public:
			Net( const vector<unsigned> &topology);
			void feedForward(const vector<double> &inputVals);
			void backProp(const vector<double> &targetVals);
			void getResults(vector<double> &resultVals) const{}; //why const here


		private:
		vector<Layer> m_layers; // m_layer[layerNum][neuronNum]
		double m_error;
		double m_recentAverageError;
		double m_recentAverageSmoothingFactor;
	};

	void Net :: backProp(const vector<double> &targetVals){
		
		//Calculate overall net eroor (RMS of output neuron errors)
		Layer &outputLayer = m_layers.back();
		m_error = 0.0;

		for (unsigned n = 0; n < outputLayer.size() - 1; ++n){
			double delta = targetVals[n] - outputLayer[n].getOutputVal();
			m_error += delta * delta;
		}

		//Implement a recent average measurement
		m_recentAverageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error) /
								(m_recentAverageSmoothingFactor + 1.0); 

		//Calculate output layer gradients
		for (unsigned n = 0; n < outputLayer.size() - 1; ++n){
			outputLayer[n].calcOutputGradients(targetVals[n]);
		}
		
		//Calculate gradients on hidden layers
		for(unsigned layerNum = m_layers.size() - 2; layerNum > 0; --layerNum){
			Layer &hiddenLayer = m_layers[layerNum];
			Layer &nextLayer = m_layers[layerNum + 1];

			for (unsigned n = 0; n < hiddenLayer.size(); ++n){
				hiddenLayer[n].calcHiddenGradients(nextLayer);
			}

		}

		//For all layers from outputs to first hidden layer update connection weights
		for (unsigned layerNum = m_layers.size() - 1; layerNum > 0; --layerNum){
			Layer &layer = m_layers[layerNum];
			Layer &prevLayer = m_layers[layerNum - 1];

			for (unsigned n= 0; n < layer.size() - 1; ++n){
				layer[n].updateInputWeights(prevLayer);
			}
		}

	}

	void Net :: feedForward(const vector<double> &inputVals){

		assert(inputVals.size() == m_layers[0].size()  -1);
		
		//assign the input values into the input neurons
		for (unsigned i = 0; i < inputVals.size(); ++i){
			m_layers[0][i].setOutputVal(inputVals.at(i));
		}

		//Forward propagate
		for (unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum) { //loops through each layer and then through each neuron to feed forward
			Layer &prevLayer = m_layers[layerNum - 1];
			for (unsigned n = 0; n < m_layers[layerNum].size() - 1; ++n){
				m_layers[layerNum][n].feedForward(prevLayer);
			}
		}

	};

	Net :: Net( const vector<unsigned> &topology){
		unsigned numLayers = topology.size();
		for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum){
			m_layers.push_back(Layer());
			unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

			//made layer, now fill it with neurons and add a bias neuron
			for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum){
				m_layers.back().push_back(Neuron(numOutputs, neuronNum));
				cout << "Made a neuron!" << endl;
			}
		}
	}


int main(){
	//ex. {3,2,1} gives us a 3 node outside later, a 2 node middle later, and 1 node output layer
	vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	vector<double> inputVals;
	myNet.feedForward(inputVals);

	vector<double> targetVals;
	myNet.backProp(targetVals);

	vector<double> resultVals;
	myNet.getResults(resultVals);

	return 0;
}