# **DISCLAIMER:**
> This documentation file is meant to represent a future structure that has yet to be implemented. 
> The restructuring also featured the renaming from LogCleaner to XMCleaner to make it more clear what this is supposed to be used with and to express this repository's aim to bring it as an optional module into the [XMRig main branch](https://github.com/xmrig/xmrig)

<details>
<summary><h2>XMCleaner</h2></summary>
<sub><i>Namespace</i></sub><br>
  <details>
  <summary><h3>Core</h3></summary>
  <sub><i>Class</sub></i><br>
  Deals with the startup and inputs. Also chains together all the processing steps. 
    <details><summary><h5>Public Members</h5></summary><details>
      <summary>Init()</summary>
      <sub><i>public member function, return <b>bool</b><br>Declaration: `public bool XMCleaner::Core.Init()`</sub></i><br>
      Is being called from main() upon starting app execution, initialises member classes and variables.
      </details>
      <details>
      <summary>Run(int argc, char* argv[])</summary>
      <sub><i>public member function, return <b>bool</b><br>Declaration: `public bool XMCleaner::Core.Run(int argc, char* argv[])</sub></i><br>
      Is being called from main() after `Core::Init()` returned `true`. Hands over the input arguments to the processing classes.
      </details>
      <details>
      <summary>Stop()</summary>
      <sub><i>public member function, <b>void</b><br>Declaration: `public void XMCleaner::Core.Stop()</i></sub><br>
      Is being called from main() after `Core::Run()` returns an `bool` in accordance to either being successful or not. Cleans up after finishing everything and frees memory again.
      </details>
    </details>
  </details>
  <details>
  <summary><h3>Converters</h3></summary>
  <sub><i>Class</sub></i><br>
    <details>
    <summary><h4>HashLog</h4></summary>
    <sub><i>Class</sub></i><br>
      <details>
      <summary><h5>Public Members</h5></summary> 
        <details>
        <summary>Convert()</summary>
        <sub><i>public member function, <b>void</b></sub></i><br>
        Takes the input `std::string` and feeds it through the processing chain of functions. After operation this parent class's member `std::string outputLine` contains the output data.
        </details>
      </details>
    <details>
    <summary><h5>Private Members</h5></summary> 
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
  <summary><h4>ShareLog</h4></summary>
  <sub><i>Class</sub></i><br>
    <details>
    <summary><h5>Public Members</h5></summary>
      <details>
      <summary>func1</summary>
      funcDescription
      </details>
    </details>
  </details>
</details>
