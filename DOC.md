|    XMCleaner   |
|:---------------|
|Namespaces
<details>
<summary><h2>XMCleaner</h2></summary>
<sub><i>Namespace</i></sub><br></br>
  <details>
  <summary>Core</summary>
  <sub><i>Class</sub></i><br></br>
  Deals with the startup and inputs. Also chains together all the processing steps. 
    <details><summary>Public Members</summary><details>
      <summary>Init()</summary>
      <sub><i>public member function, return <b>bool</b></sub></i><br></br>
      Is being called from main() upon starting app execution, initialises member classes and variables.
      </details>
      <details>
      <summary>Run()</summary>
      <sub><i>public member function, return <b>int</b></sub></i><br></br>
      Is being called from main() after `Core::Init()` returned `true`. Hands over the input arguments to the processing classes.
      </details>
      <details>
      <summary>Stop()</summary>
      <sub><i>public member function, <b>void</b></sub></i><br></br>
      Is being called from main() after `Core::Run()` returns an `int` in accordance to either being successful or not. Cleans up after finishing everything and frees memory again.
      </details>
    </details>
  </details>
  <details>
  <summary>Converters</summary>
  <sub><i>Class</sub></i><br></br>
    <details>
    <summary>HashLog</summary>
    <sub><i>Class</sub></i><br></br>
      <details>
      <summary>Public Members</summary> 
        <details>
        <summary>Convert()</summary>
        <sub><i>public member function, <b>void</b></sub></i><br></br>
        Takes the input `std::string` and feeds it through the processing chain of functions. After operation this parent class's member variable contains the output data.
        </details>
      </details>
    <details>
    <summary>Private Members</summary> 
      <details>
      <summary>func1</summary>
      funcDescription
      </details>
      <details>
      <summary>func2</summary>
      funcDescription
      </details>
    </details>
  </details>
 <details>
 <summary>ShareLog</summary>
  <details>
  <summary>Public Members</summary>
  Members
   <details>
   <summary>func1</summary>
   funcDescription
   </details>
  </details>
 </details>
</details>|