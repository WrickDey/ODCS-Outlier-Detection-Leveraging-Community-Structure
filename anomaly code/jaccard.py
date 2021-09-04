# Python3 implementation of the approach  

  
# Function to return the  
# intersection set of s1 and s2  

def intersection(s1, s2) : 

  

    # Find the intersection of the two sets  

    intersect = s1 & s2 ; 

  

    return intersect;  

  

  
# Function to return the Jaccard index of two sets  

def jaccard_index(s1, s2) : 

      

    # Sizes of both the sets  

    size_s1 = len(s1);  

    size_s2 = len(s2);  

  

    # Get the intersection set  

    intersect = intersection(s1, s2);  

  

    # Size of the intersection set  

    size_in = len(intersect);  

  

    # Calculate the Jaccard index  

    # using the formula  

    jaccard_in = size_in  / (size_s1 + size_s2 - size_in);  

  

    # Return the Jaccard index  

    return jaccard_in;  

  

  
# Function to return the Jaccard distance  

def jaccard_distance(jaccardIndex)  : 

  

    # Calculate the Jaccard distance  

    # using the formula  

    jaccard_dist = 1 - jaccardIndex;  

  

    # Return the Jaccard distance  

    return jaccard_dist;  

  
  
# Driver code  

if __name__ == "__main__" :  

  

    # Elements of the 1st set  

    s1 = set();  

    s1.add(3);  

    s1.add(5);  

    

  

    # Elements of the 2nd set

    


    s2 = set();  

    s2.add(4);  

    s2.add(2);  

    s2.add(0);  

    s2.add(7);  

    s2.add(6);
    
    s2.add(1);

    s2.add(5);

    s2.add(3);
    
   
    
  

    jaccardIndex = jaccard_index(s1, s2);  

  

    # Print the Jaccard index and Jaccard distance  

    print("Jaccard index = ",jaccardIndex);  

    print("Jaccard distance = ",jaccard_distance(jaccardIndex));  
