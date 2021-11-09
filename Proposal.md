

CS 225 Data Structures

Project Proposal (vasilis2-suhaasn3-quinnd2-yacineb2)

\1. **Leading Question:** Your ﬁnal project should have a clear conclusion or target goal

– given a dataset and a code base that implements some graph algorithms, what

can you learn from the dataset? Are you hoping to solve a speciﬁc problem? Are

you hoping to produce a general search tool? Make sure that your entire team is

on the same page for what a ‘successful’ project will look like. Be sure that your

motivating question is solvable or your proposed ﬁnal deliverable is reasonable

as you will be expected to accomplish it.

\2. **Dataset Acquisition and Processing:** Your ﬁnal project must use at least one

publicly accessible dataset and your proposal must clearly describe what dataset

you have chosen to use. As part of this description, you must state how you will

download, store, and process your data. This includes succinctly describing the

data format and clearly identifying how said data will be used in your proposed

graph data structures. Be advised that real world data is often messy and your

proposed datasets may have errors or missing entries. Your proposal should also

brieﬂy describe how your group will handle these potential errors.

We have chosen to use the OpenFlights routes dataset. It currently uses the .data

ﬁle extension, but will be downloaded locally to be converted into a csv/pandas

DataFrame. Once converted, it will be cleaned using pandas methods such as

df.dropna or scikit-learn FunctionTransformer methods. After cleaning, the

dataset will be hosted on GitHub.

\3. **Graph Algorithms:** Your ﬁnal project must implement at least two graph data

algorithms as well as a graph traversal from the list of example goals or you

must propose an algorithm or set of graph algorithms that represent an

equivalent amount of coding development. Accordingly, your proposal should

clearly state what algorithms you will complete by the projects end. When

describing your choices, be sure to include the following: What are the inputs you

expect each method to take in? What output are you expecting for each method?

If there are multiple ways to implement an algorithm, what is your target big O or

eﬃciency benchmark? For the more complex algorithms, be sure to include as

part of the input any additional information you might need. For example, A\*





search requires a heuristic. If you choose to do A\*, what are some possible

heuristics you might use?

\4. **Timeline:**

As a team, identify a list of tasks such as data acquisition, data processing, completion

of each individual algorithm, production of ﬁnal deliverables, etc… and write a proposed

timeline for the completion of these tasks. You are not required to adhere strictly to this

timeline but it should represent a reasonable set of benchmarks to strive for. For

example, stating that you will ﬁnish all graph algorithms over the span of a single week

is not reasonable. You will be expected to accomplish at least some of these tasks by

the mid-project checkin.

The data cleaning portion will be ﬁnished by the end of this week.

