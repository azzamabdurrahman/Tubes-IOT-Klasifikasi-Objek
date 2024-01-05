#ifndef UUID1868606508720
#define UUID1868606508720

/**
  * RandomForestClassifier(base_estimator=deprecated, bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator=DecisionTreeClassifier(), estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'random_state', 'ccp_alpha'), max_depth=10, max_features=sqrt, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=5, n_jobs=None, num_outputs=2, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
                    
            uint16_t votes[2] = { 0 };
            uint8_t classIdx = 0;
            float classScore = 0;

            
                tree0(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree1(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree2(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree3(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree4(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            

            // return argmax of votes
            uint8_t maxClassIdx = 0;
            float maxVote = votes[0];

            for (uint8_t i = 1; i < 2; i++) {
                if (votes[i] > maxVote) {
                    maxClassIdx = i;
                    maxVote = votes[i];
                }
            }

            predictedValue = maxClassIdx;

                    

            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }

        
            

            /**
             * Predict class label
             */
            String predictLabel(float *x) {
                return getLabelOf(predict(x));
            }

            /**
             * Get label of last prediction
             */
            String getLabel() {
                return getLabelOf(lastPrediction);
            }

            /**
             * Get label of given class
             */
            String getLabelOf(int8_t idx) {
                switch (idx) {
                    case -1:
                        return "ERROR";
                    
                        case 0:
                            return "hape";
                    
                        case 1:
                            return "kosong";
                    
                    default:
                        return "UNKNOWN";
                }
            }


            /**
             * Get latency in micros
             */
            uint32_t latencyInMicros() {
                return latency;
            }

            /**
             * Get latency in millis
             */
            uint16_t latencyInMillis() {
                return latency / 1000;
            }
            

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
            

        
            
                /**
                 * Random forest's tree #0
                 */
                void tree0(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[116] < 0.2278628647327423) {
                            
                                
                        *classIdx = 1;
                        *classScore = 141.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 152.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[120] < 0.2523450702428818) {
                            
                                
                        *classIdx = 0;
                        *classScore = 150.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 143.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[111] < 0.14151581376791) {
                            
                                
                        *classIdx = 0;
                        *classScore = 160.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[43] < 0.27971982955932617) {
                            
                                
                        *classIdx = 0;
                        *classScore = 160.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 133.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[77] < 0.45935867726802826) {
                            
                                
                        *classIdx = 0;
                        *classScore = 152.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 141.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[54] < 0.5420205295085907) {
                            
                                
                        *classIdx = 0;
                        *classScore = 156.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[126] < 0.2780584990978241) {
                            
                                
                        *classIdx = 1;
                        *classScore = 137.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 156.0;
                        return;

                            
                        }

                            
                        }

                }
            
        


            
};



static RandomForestClassifier classifier;


#endif